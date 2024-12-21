
#include <cstdint>
#include <cassert>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

// access to Simics PCI memory interface
#include "simics_pcie_memory.hpp"

// C-based forward declaration to allow DML to call into this harness
extern "C" {
    #include "tl_pcie_device.h"
}

// verilated RTL design-under-test
#include "verilated_fst_c.h"
#include "VGemminiTestHarness.h"
#if USE_TRACE==1
VerilatedFstC *tfp = NULL; // trace file descriptor
#endif
static VerilatedContext *contextp = NULL;
static VGemminiTestHarness *dut = NULL;

std::string test_name;
// #define VERBOSE (1)
uint64_t cycle_count = 0;

int rtl_init(const char* name);

typedef struct tl_resp {
    uint32_t id;
    uint32_t len;
    bool denied;
    bool is_read;
    uint8_t data[BUS_BYTES];
} tl_resp_t;

std::queue<tl_resp_t *> resp_queue;

static uint32_t beat_idx = 0;
static uint32_t total_beats = 0;

static inline uint64_t get_timestamp() {
    using namespace std::chrono;
    milliseconds ms = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()
    );
    return (uint64_t) ms.count();
}

void init_harness(conf_object_t *device UNUSED) {
    rtl_init("");
    std::cout << "[Harness] RTL callback interface has been configured" << std::endl;
}

#define step() { \
    dut->clock = 0; \
    dut->eval(); \
    contextp->timeInc(1); \
    dut->clock = 1; \
    dut->eval(); \
    contextp->timeInc(1); \
    cycle_count++; \
}

void steps(const uint64_t cycles = 1) {
    assert(dut);
    for (uint64_t i = 0; i < cycles; i++) step();
}

int rtl_init(const char* name) {
    contextp = new VerilatedContext;
    contextp->debug(0);
    test_name = name;

    #if USE_TRACE != 1
        #error USE_TRACE is expected to be 1
    #endif
    // #if USE_TRACE == 1
    Verilated::traceEverOn(true);
    // #endif

    char const *argv[] = {"program name", NULL};
    Verilated::commandArgs(1, argv);

    dut = new VGemminiTestHarness{contextp};
    // #if USE_TRACE == 1
    // assert(!(tfp->isOpen()));
    // // tfp->close();
    // tfp = new VerilatedVcdC;

    // std::cout << "before trace" << std::endl << std::flush;
    // dut->trace(tfp, 99);
    // std::cout << "after trace" << std::endl << std::flush;
    // tfp->open("gemmini.vcd");
    // #endif
    cycle_count = 0;

    dut->reset = 1;
    step();
    dut->reset = 0;

    dut->io_pcieMemReq_ready = true; // always ready to handle memory transactions
    dut->io_pcieMemResp_valid = false; // always ready to handle memory transactions
    dut->io_rocc_valid = false; // invalid command
    dut->io_rocc_bits_rs1 = 0LL;
    dut->io_rocc_bits_rs2 = 0LL;
    dut->io_rocc_bits_inst = 0;

    step();
    std::cout << std::endl << "[Harness] Starting test on RTL DUT: " << name;
    #if USE_TRACE == 1
    std::cout << " with VCD trace: " << test_name + std::string(".fst");
    #endif
    std::cout << std::endl;
    return 0;
}

void rtl_finish() {
    #if USE_TRACE == 1
    assert(tfp);
    tfp->close();
    delete tfp;
    #endif
    #if USE_COVERAGE == 1
    std::string coverage_file_name = std::string(test_name) + std::string(".dat");
    printf("[Harness] Writing coverage data to: %s\n", coverage_file_name.c_str());
    contextp->coveragep()->write(coverage_file_name.c_str());
    #endif
    assert(dut);
    dut->final();
    delete dut;
    delete contextp;
    printf("[Harness] Terminating RTL simulation\n");
}

void rocc(conf_object_t *obj, uint32 inst, uint64 rs1, uint64 rs2) {
    if (!interface_initialized()) {
        setup_pcie_interface(obj);
    }
    if (dut == NULL) {
        rtl_init("gemmini");
    }
    assert(dut);

    uint64_t start_cycle_count = cycle_count;
    std::cout << "[Harness] Sending command: inst=0x" << std::hex << inst << ", rs1=0x" << rs1 <<
        ", rs2=0x" << rs2 << std::dec << " at cycle: " << start_cycle_count << std::endl;
    uint64_t start_timestamp = get_timestamp();

    dut->io_rocc_bits_inst = inst;
    dut->io_rocc_bits_rs1 = rs1;
    dut->io_rocc_bits_rs2 = rs2;
    dut->io_rocc_valid = true; // valid command

    step();

    dut->io_rocc_valid = false; // invalid command
    dut->io_pcieMemReq_ready = true; // always ready to handle memory transactions

    while (dut->io_busy) {
        #ifdef VERBOSE
        if (cycle_count % 10 == 0) {
            std::cout << "[Harness] Step at cycle: " << cycle_count << std::endl;
        }
        #endif
        dut->io_pcieMemResp_valid = false; // no response by default

        if ((resp_queue.size() > 0) && dut->io_pcieMemResp_ready) {
            tl_resp_t *resp = resp_queue.front();
            dut->io_pcieMemResp_valid = true;
            dut->io_pcieMemResp_bits_id = resp->id;
            dut->io_pcieMemResp_bits_len = resp->len;
            dut->io_pcieMemResp_bits_denied = resp->denied;
            dut->io_pcieMemResp_bits_op = resp->is_read;
            memcpy(reinterpret_cast<uint8_t *>(dut->io_pcieMemResp_bits_data.data()), &(resp->data), BUS_BYTES);
            #ifdef VERBOSE
            std::cout << "[Harness] Popped response " << resp->id << std::endl;
            #endif
            resp_queue.pop();
            free(resp);
        }

        if (dut->io_pcieMemReq_valid) { // memory request
            tl_resp_t base_resp;
            base_resp.id = dut->io_pcieMemReq_bits_id;
            base_resp.len = dut->io_pcieMemReq_bits_len;
            base_resp.denied = false;
            base_resp.is_read = dut->io_pcieMemReq_bits_op;

            uint32_t size_in_bytes = (1 << dut->io_pcieMemReq_bits_len);

            #ifdef VERBOSE
            std::cout << "[Harness] Mem request " << base_resp.id << " type " << dut->io_pcieMemReq_bits_op << " at 0x"\
                << std::hex << dut->io_pcieMemReq_bits_addr << ", size=0x" << size_in_bytes << std::dec << std::endl;
            #endif

            if (dut->io_pcieMemReq_bits_op == 0) { // get
                // ask simics for data
                uint8_t dst_buf[size_in_bytes];
                rtl_memory_get(dut->io_pcieMemReq_bits_addr, dst_buf, size_in_bytes);

                // add response(s) to queue
                for (uint32_t i = 0; i < size_in_bytes; i += BUS_BYTES) {
                    tl_resp_t *new_resp = (tl_resp_t *) malloc(sizeof(tl_resp_t));
                    memcpy(new_resp, &base_resp, sizeof(tl_resp_t) - BUS_BYTES);
                    memcpy(&(new_resp->data), dst_buf + i, BUS_BYTES);
                    resp_queue.push(new_resp);

                    #ifdef VERBOSE
                    std::cout << "[Harness] Mem request " << new_resp->id << " read data 0x" << std::hex <<
                        ((uint64_t *) (dst_buf + i))[0] << " and 0x" <<
                        ((uint64_t *) (dst_buf + i))[1] << std::dec << std::endl;
                    #endif
                }
            } else {
                uint64_t mask = (uint64_t) (dut->io_pcieMemReq_bits_mask);

                // partial masks not supported (but some beats can be entirely 0 in multi-beat)
                uint8_t *src_buf = reinterpret_cast<uint8_t *>(dut->io_pcieMemReq_bits_data.data());

                if (total_beats == 0) {
                    total_beats = size_in_bytes / BUS_BYTES;
                    beat_idx = 0;
                }

                if (mask == ((uint64_t) (1ULL << BUS_BYTES)) - 1) {
                    rtl_memory_put(dut->io_pcieMemReq_bits_addr + beat_idx * BUS_BYTES, src_buf, BUS_BYTES);
                } else if (mask) { // fall back to byte writes if mask is partial
                    for (size_t idx = 0; idx < BUS_BYTES; idx++) {
                        if ((mask >> idx) & 1ULL) {
                            rtl_memory_put(dut->io_pcieMemReq_bits_addr + beat_idx * BUS_BYTES + idx, src_buf + idx, 1);
                        }
                    }
                }

                beat_idx += 1;
                if (beat_idx == total_beats) { // finished all beats
                    total_beats = 0;
                    // add response to queue
                    tl_resp_t *new_resp = (tl_resp_t *) malloc(sizeof(tl_resp_t));
                    memcpy(new_resp, &base_resp, sizeof(tl_resp_t) - BUS_BYTES);
                    resp_queue.push(new_resp);
                }

                #ifdef VERBOSE
                std::cout << std::hex << "[Harness] Write data 0x" <<
                    ((uint64_t *) src_buf)[0] << " and 0x" << ((uint64_t *) src_buf)[1] << std::dec << std::endl;
                #endif
            }
        }
        step();
    }
    uint64_t end_timestamp = get_timestamp();
    if (cycle_count - start_cycle_count > 10) {
        std::cout << "[Harness] Completed at " << end_timestamp << ", took " << (end_timestamp - start_timestamp) << " ms" << std::endl;
        std::cout << "[Harness] DUT at " << cycle_count << ", took " << (cycle_count - start_cycle_count) << " cycles" << std::endl;
        std::cout << "[Harness] Sim speed " << ((float) (cycle_count - start_cycle_count) / (float) (end_timestamp - start_timestamp)) << " Hz" << std::endl;
    } else {
        std::cout << "[Harness] Completed" << std::endl;
    }

    // std::cout << "[Harness] response: 0x" << std::hex << dut->io_resp_bits_data << std::dec << ", latency: " << cycle_count - start_cycle_count << " cycles" << std::endl;
    step();
}
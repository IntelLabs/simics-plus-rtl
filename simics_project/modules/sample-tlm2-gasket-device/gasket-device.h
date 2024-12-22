/*                                                              -*- C++ -*-

  © 2017 Intel Corporation

  This software and the related documents are Intel copyrighted materials, and
  your use of them is governed by the express license under which they were
  provided to you ("License"). Unless the License provides otherwise, you may
  not use, modify, copy, publish, distribute, disclose or transmit this software
  or the related documents without Intel's prior written permission.

  This software and the related documents are provided as is, with no express or
  implied warranties, other than those that are expressly stated in the License.
*/

#ifndef SAMPLE_TLM2_GASKET_DEVICE_GASKET_DEVICE_H
#define SAMPLE_TLM2_GASKET_DEVICE_GASKET_DEVICE_H

#include "VCrc32.h"
#include <verilated_vcd_c.h>
#include <verilated_vcd_sc.h>

#include <simics/systemc/simics2tlm/gasket_owner.h>
#include <simics/systemc/simics2tlm/extension_sender.h>
#include <simics/systemc/iface/extension.h>
#include <tlm_utils/simple_target_socket.h>
#include <tlm_utils/simple_initiator_socket.h>
#include <simics/systemc/context.h>
#include <simics/systemc/iface/simulation_interface.h>
#include <simics/systemc/simics2tlm/gasket_adapter.h>

#define TAG "intel/sample-dma-device"

class VerilatedVcdC;

class GasketDevice : public sc_core::sc_module {
  public:
    tlm_utils::simple_initiator_socket<GasketDevice> phys_mem_socket_;
    typedef tlm::tlm_generic_payload Payload;
    SC_CTOR(GasketDevice)
        : clock("clock")
         , reset                        ("reset")
         , io_cmd_valid                 ("io_cmd_valid")
         , io_resp_valid                ("io_resp_valid")
         , io_mem_req_ready             ("io_mem_req_ready")
         , io_mem_req_valid             ("io_mem_req_valid")
         , io_mem_req_bits_is_read      ("io_mem_req_bits_is_read")
         , io_mem_req_bits_size_in_bytes("io_mem_req_bits_size_in_bytes")
         , io_mem_resp_valid            ("io_mem_resp_valid")
         , io_busy                      ("io_busy")
         , io_cmd_bits_rs1              ("io_cmd_bits_rs1")
         , io_cmd_bits_rs2              ("io_cmd_bits_rs2")
         , io_resp_bits_data            ("io_resp_bits_data")
         , io_mem_req_bits_addr         ("io_mem_req_bits_addr")
         , io_mem_req_bits_data         ("io_mem_req_bits_data")
         , io_mem_resp_bits_data        ("io_mem_resp_bits_data")
         ,phys_mem_socket_("phys_mem")
        , crc32("crc32") {
        
          crc32.clock(clock);
crc32. reset                        (reset                        );
crc32. io_cmd_valid                 (io_cmd_valid                 );
crc32. io_resp_valid                (io_resp_valid                );
crc32. io_mem_req_ready             (io_mem_req_ready             );
crc32. io_mem_req_valid             (io_mem_req_valid             );
crc32. io_mem_req_bits_is_read      (io_mem_req_bits_is_read      );
crc32. io_mem_req_bits_size_in_bytes(io_mem_req_bits_size_in_bytes);
crc32. io_mem_resp_valid            (io_mem_resp_valid            );
crc32. io_busy                      (io_busy                      );
crc32. io_cmd_bits_rs1              (io_cmd_bits_rs1              );
crc32. io_cmd_bits_rs2              (io_cmd_bits_rs2              );
crc32. io_resp_bits_data            (io_resp_bits_data            );
crc32. io_mem_req_bits_addr         (io_mem_req_bits_addr         );
crc32. io_mem_req_bits_data         (io_mem_req_bits_data         );
crc32. io_mem_resp_bits_data        (io_mem_resp_bits_data        );




          //crc32.reset(reset);
          SC_THREAD(doClock);
          SC_THREAD(doCommand);
          SC_THREAD(doHandleMemRequest);
       tfd = new VerilatedVcdC; 
       io_mem_req_ready.write(true); // ready to accept memory requests 
    // sensitive reset
    }


  private:
VerilatedVcdC * tfd = NULL; // trace file descriptor
    
  void doCommand() {
    for( int i = 0; i < 10 ; i++)
      wait(clock.posedge_event());
    sendRequest(0x1000, 0x2000, 0x100);
  }
    
  void doHandleMemRequest() {
    while(1) {
      wait(io_mem_req_valid.posedge_event());
      printf("Got a request\n");
      char buf[1000];
      readMem(buf, io_mem_req_bits_addr.read(), 4);
      wait(clock.posedge_event());
      io_mem_resp_valid.write(true);
      wait(clock.posedge_event());
      wait(clock.posedge_event());
      io_mem_resp_valid.write(false);

    }
  }

  void doClock() {

    static int cycle_count = 0;
    Verilated::traceEverOn(true);
    crc32.trace(tfd, 99);
    tfd->open(("wave" + std::string(".vcd")).c_str());
        while(1) {
          wait(10, sc_core::SC_PS);
          clock.write(true);
        if(tfd) {
            tfd->dump(static_cast<vluint64_t>(2 * cycle_count++));
            tfd->flush();
        }
          wait(10, sc_core::SC_PS);
          clock.write(false);
        if(tfd) {
            tfd->dump(static_cast<vluint64_t>(2 * cycle_count++));
            tfd->flush();
        }
        }
  }


void readMem(void *buf, uint64_t addr, uint32_t count) {
    std::ostringstream log;
    log << "ReadMem from " << std::hex << addr << ", size " << count;

        Payload pl;
        preparePayload(&pl, addr, count, buf);
        pl.set_read();
        outboundTransaction(&pl, &dmi_src_data_);
}

void outboundTransaction(Payload *pl, tlm::tlm_dmi *dmi_data) {
    sc_core::sc_time delay = sc_core::SC_ZERO_TIME;
    Payload dmi_pl;
    dmi_pl.deep_copy_from(*pl);

    phys_mem_socket_->b_transport(*pl, delay);
    if (!pl->is_response_ok()) {
        SC_REPORT_WARNING(TAG, "Transaction failed");
    } else if (pl->is_dmi_allowed()) {
        SC_REPORT_INFO_VERB(TAG, "DMI allowed, request DMI access", sc_core::SC_HIGH);
        dmi_data->init();
        bool granted = phys_mem_socket_->get_direct_mem_ptr(dmi_pl, *dmi_data);
        SC_REPORT_INFO_VERB(TAG, granted ? "DMI granted" : "DMI not granted",
                            sc_core::SC_HIGH);
    }

    //waitMaybe(delay);
}

void preparePayload(tlm::tlm_generic_payload *pl, uint32_t addr,
                    uint32_t count, void *buf) {
    pl->set_address(addr);
    pl->set_data_length(count);
    pl->set_data_ptr(static_cast<unsigned char*>(buf));
    pl->set_streaming_width(count);
}

  void sendRequest(uint64_t src, uint64_t dst, uint64_t size) {
    io_cmd_valid.write(true);
    io_cmd_bits_rs1.write(src);
    io_cmd_bits_rs2.write(dst);
    wait(clock.posedge_event());
    io_cmd_valid.write(false);
    wait(clock.posedge_event());
    wait(clock.posedge_event());
    io_cmd_valid.write(true);
    io_cmd_bits_rs1.write(0x0);
    io_cmd_bits_rs2.write(size);
    wait(clock.posedge_event());
    io_cmd_valid.write(false);
  }

    VCrc32 crc32;
    sc_core::sc_signal<bool> clock;
    sc_core::sc_in<bool> reset;

    sc_core::sc_signal<bool> io_cmd_valid;
    sc_core::sc_signal<uint64_t> io_cmd_bits_rs1;
    sc_core::sc_signal<uint64_t> io_cmd_bits_rs2;

    sc_core::sc_signal<bool> io_mem_req_ready;
    sc_core::sc_signal<bool> io_mem_req_valid;
    sc_core::sc_signal<uint64_t> io_mem_req_bits_addr;
    sc_core::sc_signal<bool> io_mem_req_bits_is_read;
    sc_core::sc_signal<uint32_t> io_mem_req_bits_size_in_bytes;
    sc_core::sc_signal<uint64_t> io_mem_req_bits_data;
    sc_core::sc_signal<bool> io_mem_resp_valid;
    sc_core::sc_signal<uint64_t> io_mem_resp_bits_data;

    sc_core::sc_signal<bool> io_resp_valid;
    sc_core::sc_signal<uint64_t> io_resp_bits_data;

    sc_core::sc_out<bool> io_busy;
    tlm::tlm_dmi dmi_src_data_;
    tlm::tlm_dmi dmi_dst_data_;

};

// EOF_GASKET_DEVICE

// <add id="sample-tlm2-gasket-device/gasket-vector-device">
// <insert-until text="// EOF_GASKET_VECTOR_DEVICE"/></add>

#endif

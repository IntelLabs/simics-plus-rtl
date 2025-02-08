// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VCRC32_H_
#define VERILATED_VCRC32_H_  // guard

#include "systemc"
#include "verilated_sc.h"
#include "verilated.h"

class VCrc32__Syms;
class VCrc32___024root;
class VerilatedVcdSc;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) VCrc32 VL_NOT_FINAL : public ::sc_core::sc_module, public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    VCrc32__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    sc_core::sc_in<bool> &clock;
    sc_core::sc_in<bool> &reset;
    sc_core::sc_in<bool> &io_cmd_valid;
    sc_core::sc_out<bool> &io_resp_valid;
    sc_core::sc_in<bool> &io_mem_req_ready;
    sc_core::sc_out<bool> &io_mem_req_valid;
    sc_core::sc_out<bool> &io_mem_req_bits_is_read;
    sc_core::sc_out<uint32_t> &io_mem_req_bits_size_in_bytes;
    sc_core::sc_in<bool> &io_mem_resp_valid;
    sc_core::sc_out<bool> &io_busy;
    sc_core::sc_in<uint64_t> &io_cmd_bits_rs1;
    sc_core::sc_in<uint64_t> &io_cmd_bits_rs2;
    sc_core::sc_out<uint64_t> &io_resp_bits_data;
    sc_core::sc_out<uint64_t> &io_mem_req_bits_addr;
    sc_core::sc_out<uint64_t> &io_mem_req_bits_data;
    sc_core::sc_in<uint64_t> &io_mem_resp_bits_data;

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VCrc32___024root* const rootp;

    // CONSTRUCTORS
    SC_CTOR(VCrc32);
    virtual ~VCrc32();
  private:
    VL_UNCOPYABLE(VCrc32);  ///< Copying not allowed

  public:
    // API METHODS
  private:
    void eval() { eval_step(); }
    void eval_step();
  public:
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// SC tracing; avoid overloaded virtual function lint warning
    void trace(sc_core::sc_trace_file* tfp) const override { ::sc_core::sc_module::trace(tfp); }

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
};

#endif  // guard

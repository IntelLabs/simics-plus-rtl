// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VADDER_H_
#define VERILATED_VADDER_H_  // guard

#include "systemc"
#include "verilated_sc.h"
#include "verilated.h"

class VAdder__Syms;
class VAdder___024root;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) VAdder VL_NOT_FINAL : public ::sc_core::sc_module, public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    VAdder__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    sc_core::sc_in<bool> &clock;
    sc_core::sc_in<bool> &reset;
    sc_core::sc_in<bool> &io_a;
    sc_core::sc_in<bool> &io_b;
    sc_core::sc_out<bool> &io_c;

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VAdder___024root* const rootp;

    // CONSTRUCTORS
    SC_CTOR(VAdder);
    virtual ~VAdder();
  private:
    VL_UNCOPYABLE(VAdder);  ///< Copying not allowed

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
};

#endif  // guard

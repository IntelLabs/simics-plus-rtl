// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCRC32__SYMS_H_
#define VERILATED_VCRC32__SYMS_H_  // guard

#include "systemc"
#include "verilated_sc.h"
#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VCrc32.h"

// INCLUDE MODULE CLASSES
#include "VCrc32___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VCrc32__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VCrc32* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VCrc32___024root               TOP;

    // CONSTRUCTORS
    VCrc32__Syms(VerilatedContext* contextp, const char* namep, VCrc32* modelp);
    ~VCrc32__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard

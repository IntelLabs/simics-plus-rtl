// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design internal header
// See VAdder.h for the primary calling header

#ifndef VERILATED_VADDER___024ROOT_H_
#define VERILATED_VADDER___024ROOT_H_  // guard

#include "systemc"
#include "verilated_sc.h"
#include "verilated.h"


class VAdder__Syms;

class alignas(VL_CACHE_LINE_BYTES) VAdder___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __Vcellinp__Adder__clock;
    CData/*0:0*/ __Vcellinp__Adder__io_b;
    CData/*0:0*/ __Vcellinp__Adder__io_a;
    CData/*0:0*/ __Vcellinp__Adder__reset;
    CData/*0:0*/ Adder__DOT__c_delay;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP____Vcellinp__Adder__clock__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 1> Adder__DOT___RANDOM;
    sc_core::sc_in<bool> clock;
    sc_core::sc_in<bool> reset;
    sc_core::sc_in<bool> io_a;
    sc_core::sc_in<bool> io_b;
    sc_core::sc_out<bool> io_c;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VAdder__Syms* const vlSymsp;

    // CONSTRUCTORS
    VAdder___024root(VAdder__Syms* symsp, const char* v__name);
    ~VAdder___024root();
    VL_UNCOPYABLE(VAdder___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

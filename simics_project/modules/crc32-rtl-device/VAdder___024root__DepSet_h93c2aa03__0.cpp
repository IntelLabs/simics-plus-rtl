// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAdder.h for the primary calling header

#include "VAdder__pch.h"
#include "VAdder__Syms.h"
#include "VAdder___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VAdder___024root___dump_triggers__ico(VAdder___024root* vlSelf);
#endif  // VL_DEBUG

void VAdder___024root___eval_triggers__ico(VAdder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAdder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdder___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VAdder___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VAdder___024root___dump_triggers__act(VAdder___024root* vlSelf);
#endif  // VL_DEBUG

void VAdder___024root___eval_triggers__act(VAdder___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAdder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAdder___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->__Vcellinp__Adder__clock) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP____Vcellinp__Adder__clock__0))));
    vlSelf->__Vtrigprevexpr___TOP____Vcellinp__Adder__clock__0 
        = vlSelf->__Vcellinp__Adder__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VAdder___024root___dump_triggers__act(vlSelf);
    }
#endif
}

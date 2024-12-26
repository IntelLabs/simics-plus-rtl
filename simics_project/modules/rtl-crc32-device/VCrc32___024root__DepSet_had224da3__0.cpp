// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCrc32.h for the primary calling header

#include "VCrc32__pch.h"
#include "VCrc32__Syms.h"
#include "VCrc32___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VCrc32___024root___dump_triggers__ico(VCrc32___024root* vlSelf);
#endif  // VL_DEBUG

void VCrc32___024root___eval_triggers__ico(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCrc32___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCrc32___024root___dump_triggers__act(VCrc32___024root* vlSelf);
#endif  // VL_DEBUG

void VCrc32___024root___eval_triggers__act(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->__Vcellinp__Crc32__clock) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP____Vcellinp__Crc32__clock__0))));
    vlSelf->__Vtrigprevexpr___TOP____Vcellinp__Crc32__clock__0 
        = vlSelf->__Vcellinp__Crc32__clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCrc32___024root___dump_triggers__act(vlSelf);
    }
#endif
}

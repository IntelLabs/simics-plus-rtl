// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCrc32.h for the primary calling header

#include "VCrc32__pch.h"
#include "VCrc32__Syms.h"
#include "VCrc32___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VCrc32___024root___dump_triggers__stl(VCrc32___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VCrc32___024root___eval_triggers__stl(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCrc32___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

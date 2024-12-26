// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCrc32.h for the primary calling header

#include "VCrc32__pch.h"
#include "VCrc32___024root.h"

VL_ATTR_COLD void VCrc32___024root___eval_static(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___eval_static\n"); );
}

VL_ATTR_COLD void VCrc32___024root___eval_initial__TOP(VCrc32___024root* vlSelf);

VL_ATTR_COLD void VCrc32___024root___eval_initial(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___eval_initial\n"); );
    // Body
    VCrc32___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigprevexpr___TOP____Vcellinp__Crc32__clock__0 
        = vlSelf->__Vcellinp__Crc32__clock;
}

VL_ATTR_COLD void VCrc32___024root___eval_initial__TOP(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->Crc32__DOT__unnamedblk1__DOT__i = 0U;
    while ((0x108U > (IData)(vlSelf->Crc32__DOT__unnamedblk1__DOT__i))) {
        vlSelf->Crc32__DOT____Vlvbound_h8d6c2830__0 
            = VL_RANDOM_I();
        if (VL_LIKELY((0x107U >= (IData)(vlSelf->Crc32__DOT__unnamedblk1__DOT__i)))) {
            vlSelf->Crc32__DOT___RANDOM[vlSelf->Crc32__DOT__unnamedblk1__DOT__i] 
                = vlSelf->Crc32__DOT____Vlvbound_h8d6c2830__0;
        }
        vlSelf->Crc32__DOT__unnamedblk1__DOT__i = (0x1ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->Crc32__DOT__unnamedblk1__DOT__i)));
    }
    vlSelf->Crc32__DOT__state = (3U & vlSelf->Crc32__DOT___RANDOM
                                 [0x100U]);
    vlSelf->Crc32__DOT__src_addr = (((QData)((IData)(
                                                     (vlSelf->Crc32__DOT___RANDOM
                                                      [0x100U] 
                                                      >> 2U))) 
                                     << 0x22U) | (((QData)((IData)(
                                                                   vlSelf->Crc32__DOT___RANDOM
                                                                   [0x101U])) 
                                                   << 2U) 
                                                  | (QData)((IData)(
                                                                    (3U 
                                                                     & vlSelf->Crc32__DOT___RANDOM
                                                                     [0x102U])))));
    vlSelf->Crc32__DOT__dst_addr = (((QData)((IData)(
                                                     (vlSelf->Crc32__DOT___RANDOM
                                                      [0x102U] 
                                                      >> 2U))) 
                                     << 0x22U) | (((QData)((IData)(
                                                                   vlSelf->Crc32__DOT___RANDOM
                                                                   [0x103U])) 
                                                   << 2U) 
                                                  | (QData)((IData)(
                                                                    (3U 
                                                                     & vlSelf->Crc32__DOT___RANDOM
                                                                     [0x104U])))));
    vlSelf->Crc32__DOT__len = (((QData)((IData)((vlSelf->Crc32__DOT___RANDOM
                                                 [0x104U] 
                                                 >> 2U))) 
                                << 0x22U) | (((QData)((IData)(
                                                              vlSelf->Crc32__DOT___RANDOM
                                                              [0x105U])) 
                                              << 2U) 
                                             | (QData)((IData)(
                                                               (3U 
                                                                & vlSelf->Crc32__DOT___RANDOM
                                                                [0x106U])))));
    vlSelf->Crc32__DOT__crc32_val = ((0xfffffffcU & 
                                      vlSelf->Crc32__DOT___RANDOM
                                      [0x106U]) | (3U 
                                                   & vlSelf->Crc32__DOT___RANDOM
                                                   [0x107U]));
}

VL_ATTR_COLD void VCrc32___024root___eval_final(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCrc32___024root___dump_triggers__stl(VCrc32___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VCrc32___024root___eval_phase__stl(VCrc32___024root* vlSelf);

VL_ATTR_COLD void VCrc32___024root___eval_settle(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VCrc32___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("build/chisel/Crc32.sv", 64, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VCrc32___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCrc32___024root___dump_triggers__stl(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VCrc32___024root___stl_sequent__TOP__0(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___stl_sequent__TOP__0\n"); );
    // Body
    VL_ASSIGN_ISI(1,vlSelf->__Vcellinp__Crc32__clock, vlSelf->clock);
    VL_ASSIGN_ISI(1,vlSelf->__Vcellinp__Crc32__reset, vlSelf->reset);
    if ((1U == (IData)(vlSelf->Crc32__DOT__state))) {
        vlSelf->__Vcellout__Crc32__io_mem_req_bits_is_read = 1U;
        VL_ASSIGN_SII(1,vlSelf->io_mem_req_bits_is_read, 1U);
        VL_ASSIGN_SII(4,vlSelf->io_mem_req_bits_size_in_bytes, 1U);
        VL_ASSIGN_SQQ(64,vlSelf->io_mem_req_bits_addr, vlSelf->Crc32__DOT__src_addr);
    } else {
        vlSelf->__Vcellout__Crc32__io_mem_req_bits_is_read = 0U;
        VL_ASSIGN_SII(1,vlSelf->io_mem_req_bits_is_read, 0U);
        VL_ASSIGN_SII(4,vlSelf->io_mem_req_bits_size_in_bytes, 4U);
        VL_ASSIGN_SQQ(64,vlSelf->io_mem_req_bits_addr, vlSelf->Crc32__DOT__dst_addr);
    }
    VL_ASSIGN_SII(1,vlSelf->io_busy, (0U != (IData)(vlSelf->Crc32__DOT__state)));
    VL_ASSIGN_SQQ(64,vlSelf->io_resp_bits_data, (QData)((IData)(
                                                                (~ vlSelf->Crc32__DOT__crc32_val))));
    VL_ASSIGN_SQQ(64,vlSelf->io_mem_req_bits_data, (QData)((IData)(
                                                                   (~ vlSelf->Crc32__DOT__crc32_val))));
    VL_ASSIGN_ISI(1,vlSelf->__Vcellinp__Crc32__io_mem_resp_valid, vlSelf->io_mem_resp_valid);
    VL_ASSIGN_QSQ(64,vlSelf->__Vcellinp__Crc32__io_cmd_bits_rs2, vlSelf->io_cmd_bits_rs2);
    VL_ASSIGN_ISI(1,vlSelf->__Vcellinp__Crc32__io_mem_req_ready, vlSelf->io_mem_req_ready);
    VL_ASSIGN_QSQ(64,vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data, vlSelf->io_mem_resp_bits_data);
    VL_ASSIGN_QSQ(64,vlSelf->__Vcellinp__Crc32__io_cmd_bits_rs1, vlSelf->io_cmd_bits_rs1);
    vlSelf->Crc32__DOT___GEN_2 = ((1U == (IData)(vlSelf->Crc32__DOT__state)) 
                                  | (2U == (IData)(vlSelf->Crc32__DOT__state)));
    VL_ASSIGN_ISI(1,vlSelf->__Vcellinp__Crc32__io_cmd_valid, vlSelf->io_cmd_valid);
    vlSelf->Crc32__DOT__casez_tmp = ((1U & ((vlSelf->Crc32__DOT__crc32_val 
                                             >> 7U) 
                                            ^ (IData)(
                                                      (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                       >> 7U))))
                                      ? ((1U & ((vlSelf->Crc32__DOT__crc32_val 
                                                 >> 6U) 
                                                ^ (IData)(
                                                          (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                           >> 6U))))
                                          ? ((1U & 
                                              ((vlSelf->Crc32__DOT__crc32_val 
                                                >> 5U) 
                                               ^ (IData)(
                                                         (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                          >> 5U))))
                                              ? ((1U 
                                                  & ((vlSelf->Crc32__DOT__crc32_val 
                                                      >> 4U) 
                                                     ^ (IData)(
                                                               (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                >> 4U))))
                                                  ? 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x2d02ef8dU
                                                      : 0x5a05df1bU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xc30c8ea1U
                                                      : 0xb40bbe37U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x2a6f2b94U
                                                      : 0x5d681b02U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xc4614ab8U
                                                      : 0xb3667a2eU)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x23d967bfU
                                                      : 0x54de5729U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xcdd70693U
                                                      : 0xbad03605U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x24b4a3a6U
                                                      : 0x53b39330U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xcabac28aU
                                                      : 0xbdbdf21cU))))
                                                  : 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x30b5ffe9U
                                                      : 0x47b2cf7fU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xdebb9ec5U
                                                      : 0xa9bcae53U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x37d83bf0U
                                                      : 0x40df0b66U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xd9d65adcU
                                                      : 0xaed16a4aU)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x3e6e77dbU
                                                      : 0x4969474dU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xd06016f7U
                                                      : 0xa7672661U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x3903b3c2U
                                                      : 0x4e048354U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xd70dd2eeU
                                                      : 0xa00ae278U)))))
                                              : ((1U 
                                                  & ((vlSelf->Crc32__DOT__crc32_val 
                                                      >> 4U) 
                                                     ^ (IData)(
                                                               (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                >> 4U))))
                                                  ? 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x166ccf45U
                                                      : 0x616bffd3U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xf862ae69U
                                                      : 0x8f659effU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x11010b5cU
                                                      : 0x66063bcaU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xff0f6a70U
                                                      : 0x88085ae6U)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x18b74777U
                                                      : 0x6fb077e1U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xf6b9265bU
                                                      : 0x81be16cdU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x1fda836eU
                                                      : 0x68ddb3f8U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xf1d4e242U
                                                      : 0x86d3d2d4U))))
                                                  : 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xbdbdf21U
                                                      : 0x7cdcefb7U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xe5d5be0dU
                                                      : 0x92d28e9bU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xcb61b38U
                                                      : 0x7bb12baeU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xe2b87a14U
                                                      : 0x95bf4a82U)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x5005713U
                                                      : 0x72076785U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xeb0e363fU
                                                      : 0x9c0906a9U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x26d930aU
                                                      : 0x756aa39cU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xec63f226U
                                                      : 0x9b64c2b0U))))))
                                          : ((1U & 
                                              ((vlSelf->Crc32__DOT__crc32_val 
                                                >> 5U) 
                                               ^ (IData)(
                                                         (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                          >> 5U))))
                                              ? ((1U 
                                                  & ((vlSelf->Crc32__DOT__crc32_val 
                                                      >> 4U) 
                                                     ^ (IData)(
                                                               (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                >> 4U))))
                                                  ? 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x5bdeae1dU
                                                      : 0x2cd99e8bU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xb5d0cf31U
                                                      : 0xc2d7ffa7U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x5cb36a04U
                                                      : 0x2bb45a92U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xb2bd0b28U
                                                      : 0xc5ba3bbeU)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x5505262fU
                                                      : 0x220216b9U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xbb0b4703U
                                                      : 0xcc0c7795U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x5268e236U
                                                      : 0x256fd2a0U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xbc66831aU
                                                      : 0xcb61b38cU))))
                                                  : 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x4669be79U
                                                      : 0x316e8eefU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xa867df55U
                                                      : 0xdf60efc3U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x41047a60U
                                                      : 0x36034af6U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xaf0a1b4cU
                                                      : 0xd80d2bdaU)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x48b2364bU
                                                      : 0x3fb506ddU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xa6bc5767U
                                                      : 0xd1bb67f1U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x4fdff252U
                                                      : 0x38d8c2c4U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xa1d1937eU
                                                      : 0xd6d6a3e8U)))))
                                              : ((1U 
                                                  & ((vlSelf->Crc32__DOT__crc32_val 
                                                      >> 4U) 
                                                     ^ (IData)(
                                                               (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                >> 4U))))
                                                  ? 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x60b08ed5U
                                                      : 0x17b7be43U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x8ebeeff9U
                                                      : 0xf9b9df6fU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x67dd4accU
                                                      : 0x10da7a5aU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x89d32be0U
                                                      : 0xfed41b76U)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x6e6b06e7U
                                                      : 0x196c3671U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x806567cbU
                                                      : 0xf762575dU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x6906c2feU
                                                      : 0x1e01f268U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x8708a3d2U
                                                      : 0xf00f9344U))))
                                                  : 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x7d079eb1U
                                                      : 0xa00ae27U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x9309ff9dU
                                                      : 0xe40ecf0bU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x7a6a5aa8U
                                                      : 0xd6d6a3eU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x94643b84U
                                                      : 0xe3630b12U)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x73dc1683U
                                                      : 0x4db2615U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x9dd277afU
                                                      : 0xead54739U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x74b1d29aU
                                                      : 0x3b6e20cU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x9abfb3b6U
                                                      : 0xedb88320U)))))))
                                      : ((1U & ((vlSelf->Crc32__DOT__crc32_val 
                                                 >> 6U) 
                                                ^ (IData)(
                                                          (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                           >> 6U))))
                                          ? ((1U & 
                                              ((vlSelf->Crc32__DOT__crc32_val 
                                                >> 5U) 
                                               ^ (IData)(
                                                         (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                          >> 5U))))
                                              ? ((1U 
                                                  & ((vlSelf->Crc32__DOT__crc32_val 
                                                      >> 4U) 
                                                     ^ (IData)(
                                                               (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                >> 4U))))
                                                  ? 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xc0ba6cadU
                                                      : 0xb7bd5c3bU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x2eb40d81U
                                                      : 0x59b33d17U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xc7d7a8b4U
                                                      : 0xb0d09822U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x29d9c998U
                                                      : 0x5edef90eU)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xce61e49fU
                                                      : 0xb966d409U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x206f85b3U
                                                      : 0x5768b525U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xc90c2086U
                                                      : 0xbe0b1010U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x270241aaU
                                                      : 0x5005713cU))))
                                                  : 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xdd0d7cc9U
                                                      : 0xaa0a4c5fU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x33031de5U
                                                      : 0x44042d73U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xda60b8d0U
                                                      : 0xad678846U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x346ed9fcU
                                                      : 0x4369e96aU)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xd3d6f4fbU
                                                      : 0xa4d1c46dU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x3dd895d7U
                                                      : 0x4adfa541U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xd4bb30e2U
                                                      : 0xa3bc0074U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x3ab551ceU
                                                      : 0x4db26158U)))))
                                              : ((1U 
                                                  & ((vlSelf->Crc32__DOT__crc32_val 
                                                      >> 4U) 
                                                     ^ (IData)(
                                                               (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                >> 4U))))
                                                  ? 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xfbd44c65U
                                                      : 0x8cd37cf3U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x15da2d49U
                                                      : 0x62dd1ddfU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xfcb9887cU
                                                      : 0x8bbeb8eaU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x12b7e950U
                                                      : 0x65b0d9c6U)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xf50fc457U
                                                      : 0x8208f4c1U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x1b01a57bU
                                                      : 0x6c0695edU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xf262004eU
                                                      : 0x856530d8U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x1c6c6162U
                                                      : 0x6b6b51f4U))))
                                                  : 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xe6635c01U
                                                      : 0x91646c97U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x86d3d2dU
                                                      : 0x7f6a0dbbU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xe10e9818U
                                                      : 0x9609a88eU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xf00f934U
                                                      : 0x7807c9a2U)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xe8b8d433U
                                                      : 0x9fbfe4a5U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x6b6b51fU
                                                      : 0x71b18589U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xefd5102aU
                                                      : 0x98d220bcU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x1db7106U
                                                      : 0x76dc4190U))))))
                                          : ((1U & 
                                              ((vlSelf->Crc32__DOT__crc32_val 
                                                >> 5U) 
                                               ^ (IData)(
                                                         (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                          >> 5U))))
                                              ? ((1U 
                                                  & ((vlSelf->Crc32__DOT__crc32_val 
                                                      >> 4U) 
                                                     ^ (IData)(
                                                               (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                >> 4U))))
                                                  ? 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xb6662d3dU
                                                      : 0xc1611dabU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x58684c11U
                                                      : 0x2f6f7c87U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xb10be924U
                                                      : 0xc60cd9b2U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x5f058808U
                                                      : 0x2802b89eU)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xb8bda50fU
                                                      : 0xcfba9599U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x56b3c423U
                                                      : 0x21b4f4b5U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xbfd06116U
                                                      : 0xc8d75180U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x51de003aU
                                                      : 0x26d930acU))))
                                                  : 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xabd13d59U
                                                      : 0xdcd60dcfU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x45df5c75U
                                                      : 0x32d86ce3U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xacbcf940U
                                                      : 0xdbbbc9d6U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x42b2986cU
                                                      : 0x35b5a8faU)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xa50ab56bU
                                                      : 0xd20d85fdU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x4b04d447U
                                                      : 0x3c03e4d1U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0xa2677172U
                                                      : 0xd56041e4U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x4c69105eU
                                                      : 0x3b6e20c8U)))))
                                              : ((1U 
                                                  & ((vlSelf->Crc32__DOT__crc32_val 
                                                      >> 4U) 
                                                     ^ (IData)(
                                                               (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                >> 4U))))
                                                  ? 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x8d080df5U
                                                      : 0xfa0f3d63U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x63066cd9U
                                                      : 0x14015c4fU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x8a65c9ecU
                                                      : 0xfd62f97aU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x646ba8c0U
                                                      : 0x136c9856U)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x83d385c7U
                                                      : 0xf4d4b551U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x6ddde4ebU
                                                      : 0x1adad47dU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x84be41deU
                                                      : 0xf3b97148U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x6ab020f2U
                                                      : 0x1db71064U))))
                                                  : 
                                                 ((1U 
                                                   & ((vlSelf->Crc32__DOT__crc32_val 
                                                       >> 3U) 
                                                      ^ (IData)(
                                                                (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                 >> 3U))))
                                                   ? 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x90bf1d91U
                                                      : 0xe7b82d07U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x7eb17cbdU
                                                      : 0x9b64c2bU))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x97d2d988U
                                                      : 0xe0d5e91eU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x79dcb8a4U
                                                      : 0xedb8832U)))
                                                   : 
                                                  ((1U 
                                                    & ((vlSelf->Crc32__DOT__crc32_val 
                                                        >> 2U) 
                                                       ^ (IData)(
                                                                 (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                  >> 2U))))
                                                    ? 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x9e6495a3U
                                                      : 0xe963a535U)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x706af48fU
                                                      : 0x76dc419U))
                                                    : 
                                                   ((1U 
                                                     & ((vlSelf->Crc32__DOT__crc32_val 
                                                         >> 1U) 
                                                        ^ (IData)(
                                                                  (vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data 
                                                                   >> 1U))))
                                                     ? 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x990951baU
                                                      : 0xee0e612cU)
                                                     : 
                                                    ((1U 
                                                      & (vlSelf->Crc32__DOT__crc32_val 
                                                         ^ (IData)(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data)))
                                                      ? 0x77073096U
                                                      : 0U))))))));
    vlSelf->Crc32__DOT___GEN_5 = (1U | (((0U != vlSelf->__Vcellinp__Crc32__io_cmd_bits_rs1) 
                                         | (0ULL == vlSelf->__Vcellinp__Crc32__io_cmd_bits_rs2)) 
                                        << 1U));
    vlSelf->Crc32__DOT___GEN_6 = (1U & ((~ (IData)(
                                                   (3U 
                                                    == (IData)(vlSelf->Crc32__DOT__state)))) 
                                        | (IData)(vlSelf->Crc32__DOT___GEN_2)));
    vlSelf->Crc32__DOT___GEN = ((0U == (IData)(vlSelf->Crc32__DOT__state)) 
                                & (IData)(vlSelf->__Vcellinp__Crc32__io_cmd_valid));
    vlSelf->Crc32__DOT___GEN_0 = ((IData)(vlSelf->Crc32__DOT___GEN) 
                                  & (0U != vlSelf->__Vcellinp__Crc32__io_cmd_bits_rs1));
    vlSelf->Crc32__DOT___GEN_3 = ((IData)(vlSelf->Crc32__DOT___GEN) 
                                  | (IData)(vlSelf->Crc32__DOT___GEN_2));
    vlSelf->__Vcellout__Crc32__io_mem_req_valid = (
                                                   (~ (IData)(vlSelf->Crc32__DOT___GEN)) 
                                                   & (IData)(vlSelf->Crc32__DOT___GEN_2));
    VL_ASSIGN_SII(1,vlSelf->io_resp_valid, ((~ (IData)(vlSelf->Crc32__DOT___GEN_3)) 
                                            & (3U == (IData)(vlSelf->Crc32__DOT__state))));
    VL_ASSIGN_SII(1,vlSelf->io_mem_req_valid, vlSelf->__Vcellout__Crc32__io_mem_req_valid);
    vlSelf->Crc32__DOT___GEN_7 = ((IData)(vlSelf->__Vcellinp__Crc32__io_mem_req_ready) 
                                  & (IData)(vlSelf->__Vcellout__Crc32__io_mem_req_valid));
}

VL_ATTR_COLD void VCrc32___024root___eval_stl(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VCrc32___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void VCrc32___024root___eval_triggers__stl(VCrc32___024root* vlSelf);

VL_ATTR_COLD bool VCrc32___024root___eval_phase__stl(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VCrc32___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VCrc32___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCrc32___024root___dump_triggers__ico(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCrc32___024root___dump_triggers__act(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge __Vcellinp__Crc32__clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCrc32___024root___dump_triggers__nba(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge __Vcellinp__Crc32__clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VCrc32___024root___ctor_var_reset(VCrc32___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data = VL_RAND_RESET_Q(64);
    vlSelf->__Vcellinp__Crc32__io_mem_resp_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__Crc32__io_mem_req_bits_is_read = VL_RAND_RESET_I(1);
    vlSelf->__Vcellout__Crc32__io_mem_req_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__Crc32__io_mem_req_ready = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__Crc32__io_cmd_bits_rs2 = VL_RAND_RESET_Q(64);
    vlSelf->__Vcellinp__Crc32__io_cmd_bits_rs1 = VL_RAND_RESET_Q(64);
    vlSelf->__Vcellinp__Crc32__io_cmd_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__Crc32__reset = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__Crc32__clock = VL_RAND_RESET_I(1);
    vlSelf->Crc32__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->Crc32__DOT__src_addr = VL_RAND_RESET_Q(64);
    vlSelf->Crc32__DOT__dst_addr = VL_RAND_RESET_Q(64);
    vlSelf->Crc32__DOT__len = VL_RAND_RESET_Q(64);
    vlSelf->Crc32__DOT__crc32_val = VL_RAND_RESET_I(32);
    vlSelf->Crc32__DOT___GEN = VL_RAND_RESET_I(1);
    vlSelf->Crc32__DOT___GEN_0 = VL_RAND_RESET_I(1);
    vlSelf->Crc32__DOT___GEN_2 = VL_RAND_RESET_I(1);
    vlSelf->Crc32__DOT___GEN_3 = VL_RAND_RESET_I(1);
    vlSelf->Crc32__DOT__casez_tmp = VL_RAND_RESET_I(32);
    vlSelf->Crc32__DOT___GEN_5 = VL_RAND_RESET_I(2);
    vlSelf->Crc32__DOT___GEN_6 = VL_RAND_RESET_I(1);
    vlSelf->Crc32__DOT___GEN_7 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 264; ++__Vi0) {
        vlSelf->Crc32__DOT___RANDOM[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->Crc32__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(9);
    vlSelf->Crc32__DOT____Vlvbound_h8d6c2830__0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP____Vcellinp__Crc32__clock__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

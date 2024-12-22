// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_sc.h"
#include "VCrc32__Syms.h"


void VCrc32___024root__trace_chg_0_sub_0(VCrc32___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VCrc32___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root__trace_chg_0\n"); );
    // Init
    VCrc32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCrc32___024root*>(voidSelf);
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VCrc32___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VCrc32___024root__trace_chg_0_sub_0(VCrc32___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgSData(oldp+0,(vlSelf->Crc32__DOT__unnamedblk1__DOT__i),9);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+1,(vlSelf->__Vcellinp__Crc32__clock));
        bufp->chgBit(oldp+2,(vlSelf->__Vcellinp__Crc32__reset));
        bufp->chgBit(oldp+3,(vlSelf->__Vcellinp__Crc32__io_cmd_valid));
        bufp->chgQData(oldp+4,(vlSelf->__Vcellinp__Crc32__io_cmd_bits_rs1),64);
        bufp->chgQData(oldp+6,(vlSelf->__Vcellinp__Crc32__io_cmd_bits_rs2),64);
        bufp->chgBit(oldp+8,(vlSelf->__Vcellinp__Crc32__io_mem_req_ready));
        bufp->chgBit(oldp+9,(vlSelf->__Vcellinp__Crc32__io_mem_resp_valid));
        bufp->chgQData(oldp+10,(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data),64);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgQData(oldp+12,((QData)((IData)((~ vlSelf->Crc32__DOT__crc32_val)))),64);
        bufp->chgBit(oldp+14,((1U == (IData)(vlSelf->Crc32__DOT__state))));
        bufp->chgCData(oldp+15,(((1U == (IData)(vlSelf->Crc32__DOT__state))
                                  ? 1U : 4U)),4);
        bufp->chgQData(oldp+16,(((1U == (IData)(vlSelf->Crc32__DOT__state))
                                  ? vlSelf->Crc32__DOT__src_addr
                                  : vlSelf->Crc32__DOT__dst_addr)),64);
        bufp->chgBit(oldp+18,((0U != (IData)(vlSelf->Crc32__DOT__state))));
        bufp->chgCData(oldp+19,(vlSelf->Crc32__DOT__state),2);
        bufp->chgQData(oldp+20,(vlSelf->Crc32__DOT__src_addr),64);
        bufp->chgQData(oldp+22,(vlSelf->Crc32__DOT__dst_addr),64);
        bufp->chgQData(oldp+24,(vlSelf->Crc32__DOT__len),64);
        bufp->chgIData(oldp+26,(vlSelf->Crc32__DOT__crc32_val),32);
    }
    bufp->chgBit(oldp+27,(((~ (IData)(vlSelf->Crc32__DOT___GEN_3)) 
                           & (3U == (IData)(vlSelf->Crc32__DOT__state)))));
    bufp->chgBit(oldp+28,(vlSelf->__Vcellout__Crc32__io_mem_req_valid));
    bufp->chgIData(oldp+29,(vlSelf->Crc32__DOT__casez_tmp),32);
}

void VCrc32___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root__trace_cleanup\n"); );
    // Init
    VCrc32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCrc32___024root*>(voidSelf);
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}

// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_sc.h"
#include "VCrc32__Syms.h"


VL_ATTR_COLD void VCrc32___024root__trace_init_sub__TOP__0(VCrc32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("Crc32", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+2,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"io_cmd_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+5,0,"io_cmd_bits_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+7,0,"io_cmd_bits_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+28,0,"io_resp_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+13,0,"io_resp_bits_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+9,0,"io_mem_req_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"io_mem_req_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"io_mem_req_bits_is_read",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"io_mem_req_bits_size_in_bytes",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declQuad(c+17,0,"io_mem_req_bits_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+13,0,"io_mem_req_bits_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+10,0,"io_mem_resp_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+11,0,"io_mem_resp_bits_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+19,0,"io_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declQuad(c+21,0,"src_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+23,0,"dst_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+25,0,"len",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+27,0,"crc32_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+15,0,"io_mem_req_bits_is_read_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"io_mem_req_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+17,0,"io_mem_req_bits_addr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+13,0,"io_mem_req_bits_data_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+13,0,"io_resp_bits_data_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+30,0,"casez_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VCrc32___024root__trace_init_top(VCrc32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root__trace_init_top\n"); );
    // Body
    VCrc32___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VCrc32___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VCrc32___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VCrc32___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VCrc32___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VCrc32___024root__trace_register(VCrc32___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&VCrc32___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VCrc32___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VCrc32___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VCrc32___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VCrc32___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root__trace_const_0\n"); );
    // Init
    VCrc32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCrc32___024root*>(voidSelf);
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VCrc32___024root__trace_full_0_sub_0(VCrc32___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VCrc32___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root__trace_full_0\n"); );
    // Init
    VCrc32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCrc32___024root*>(voidSelf);
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VCrc32___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VCrc32___024root__trace_full_0_sub_0(VCrc32___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCrc32___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(vlSelf->Crc32__DOT__unnamedblk1__DOT__i),9);
    bufp->fullBit(oldp+2,(vlSelf->__Vcellinp__Crc32__clock));
    bufp->fullBit(oldp+3,(vlSelf->__Vcellinp__Crc32__reset));
    bufp->fullBit(oldp+4,(vlSelf->__Vcellinp__Crc32__io_cmd_valid));
    bufp->fullQData(oldp+5,(vlSelf->__Vcellinp__Crc32__io_cmd_bits_rs1),64);
    bufp->fullQData(oldp+7,(vlSelf->__Vcellinp__Crc32__io_cmd_bits_rs2),64);
    bufp->fullBit(oldp+9,(vlSelf->__Vcellinp__Crc32__io_mem_req_ready));
    bufp->fullBit(oldp+10,(vlSelf->__Vcellinp__Crc32__io_mem_resp_valid));
    bufp->fullQData(oldp+11,(vlSelf->__Vcellinp__Crc32__io_mem_resp_bits_data),64);
    bufp->fullQData(oldp+13,((QData)((IData)((~ vlSelf->Crc32__DOT__crc32_val)))),64);
    bufp->fullBit(oldp+15,((1U == (IData)(vlSelf->Crc32__DOT__state))));
    bufp->fullCData(oldp+16,(((1U == (IData)(vlSelf->Crc32__DOT__state))
                               ? 1U : 4U)),4);
    bufp->fullQData(oldp+17,(((1U == (IData)(vlSelf->Crc32__DOT__state))
                               ? vlSelf->Crc32__DOT__src_addr
                               : vlSelf->Crc32__DOT__dst_addr)),64);
    bufp->fullBit(oldp+19,((0U != (IData)(vlSelf->Crc32__DOT__state))));
    bufp->fullCData(oldp+20,(vlSelf->Crc32__DOT__state),2);
    bufp->fullQData(oldp+21,(vlSelf->Crc32__DOT__src_addr),64);
    bufp->fullQData(oldp+23,(vlSelf->Crc32__DOT__dst_addr),64);
    bufp->fullQData(oldp+25,(vlSelf->Crc32__DOT__len),64);
    bufp->fullIData(oldp+27,(vlSelf->Crc32__DOT__crc32_val),32);
    bufp->fullBit(oldp+28,(((~ (IData)(vlSelf->Crc32__DOT___GEN_3)) 
                            & (3U == (IData)(vlSelf->Crc32__DOT__state)))));
    bufp->fullBit(oldp+29,(vlSelf->__Vcellout__Crc32__io_mem_req_valid));
    bufp->fullIData(oldp+30,(vlSelf->Crc32__DOT__casez_tmp),32);
}

// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCrc32.h for the primary calling header

#ifndef VERILATED_VCRC32___024ROOT_H_
#define VERILATED_VCRC32___024ROOT_H_  // guard

#include "systemc"
#include "verilated_sc.h"
#include "verilated.h"


class VCrc32__Syms;

class alignas(VL_CACHE_LINE_BYTES) VCrc32___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __Vcellinp__Crc32__clock;
    CData/*0:0*/ __Vcellinp__Crc32__io_mem_resp_valid;
    CData/*0:0*/ __Vcellout__Crc32__io_mem_req_bits_is_read;
    CData/*0:0*/ __Vcellout__Crc32__io_mem_req_valid;
    CData/*0:0*/ __Vcellinp__Crc32__io_mem_req_ready;
    CData/*0:0*/ __Vcellinp__Crc32__io_cmd_valid;
    CData/*0:0*/ __Vcellinp__Crc32__reset;
    CData/*1:0*/ Crc32__DOT__state;
    CData/*0:0*/ Crc32__DOT___GEN;
    CData/*0:0*/ Crc32__DOT___GEN_0;
    CData/*0:0*/ Crc32__DOT___GEN_2;
    CData/*0:0*/ Crc32__DOT___GEN_3;
    CData/*1:0*/ Crc32__DOT___GEN_5;
    CData/*0:0*/ Crc32__DOT___GEN_6;
    CData/*0:0*/ Crc32__DOT___GEN_7;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP____Vcellinp__Crc32__clock__0;
    CData/*0:0*/ __VactContinue;
    SData/*8:0*/ Crc32__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ Crc32__DOT__crc32_val;
    IData/*31:0*/ Crc32__DOT__casez_tmp;
    IData/*31:0*/ Crc32__DOT____Vlvbound_h8d6c2830__0;
    IData/*31:0*/ __VactIterCount;
    QData/*63:0*/ __Vcellinp__Crc32__io_mem_resp_bits_data;
    QData/*63:0*/ __Vcellinp__Crc32__io_cmd_bits_rs2;
    QData/*63:0*/ __Vcellinp__Crc32__io_cmd_bits_rs1;
    QData/*63:0*/ Crc32__DOT__src_addr;
    QData/*63:0*/ Crc32__DOT__dst_addr;
    QData/*63:0*/ Crc32__DOT__len;
    VlUnpacked<IData/*31:0*/, 264> Crc32__DOT___RANDOM;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    sc_core::sc_in<bool> clock;
    sc_core::sc_in<bool> reset;
    sc_core::sc_in<bool> io_cmd_valid;
    sc_core::sc_out<bool> io_resp_valid;
    sc_core::sc_in<bool> io_mem_req_ready;
    sc_core::sc_out<bool> io_mem_req_valid;
    sc_core::sc_out<bool> io_mem_req_bits_is_read;
    sc_core::sc_out<uint32_t> io_mem_req_bits_size_in_bytes;
    sc_core::sc_in<bool> io_mem_resp_valid;
    sc_core::sc_out<bool> io_busy;
    sc_core::sc_in<uint64_t> io_cmd_bits_rs1;
    sc_core::sc_in<uint64_t> io_cmd_bits_rs2;
    sc_core::sc_out<uint64_t> io_resp_bits_data;
    sc_core::sc_out<uint64_t> io_mem_req_bits_addr;
    sc_core::sc_out<uint64_t> io_mem_req_bits_data;
    sc_core::sc_in<uint64_t> io_mem_resp_bits_data;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VCrc32__Syms* const vlSymsp;

    // CONSTRUCTORS
    VCrc32___024root(VCrc32__Syms* symsp, const char* v__name);
    ~VCrc32___024root();
    VL_UNCOPYABLE(VCrc32___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

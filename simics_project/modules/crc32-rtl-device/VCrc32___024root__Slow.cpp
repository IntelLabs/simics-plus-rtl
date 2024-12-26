// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCrc32.h for the primary calling header

#include "VCrc32__pch.h"
#include "VCrc32__Syms.h"
#include "VCrc32___024root.h"

void VCrc32___024root___ctor_var_reset(VCrc32___024root* vlSelf);

VCrc32___024root::VCrc32___024root(VCrc32__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , clock("clock")
    , reset("reset")
    , io_cmd_valid("io_cmd_valid")
    , io_resp_valid("io_resp_valid")
    , io_mem_req_ready("io_mem_req_ready")
    , io_mem_req_valid("io_mem_req_valid")
    , io_mem_req_bits_is_read("io_mem_req_bits_is_read")
    , io_mem_req_bits_size_in_bytes("io_mem_req_bits_size_in_bytes")
    , io_mem_resp_valid("io_mem_resp_valid")
    , io_busy("io_busy")
    , io_cmd_bits_rs1("io_cmd_bits_rs1")
    , io_cmd_bits_rs2("io_cmd_bits_rs2")
    , io_resp_bits_data("io_resp_bits_data")
    , io_mem_req_bits_addr("io_mem_req_bits_addr")
    , io_mem_req_bits_data("io_mem_req_bits_data")
    , io_mem_resp_bits_data("io_mem_resp_bits_data")
    , vlSymsp{symsp}
 {
    // Reset structure values
    VCrc32___024root___ctor_var_reset(this);
}

void VCrc32___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VCrc32___024root::~VCrc32___024root() {
}

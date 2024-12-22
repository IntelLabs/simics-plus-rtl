// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VCrc32__pch.h"
#include "VCrc32.h"
#include "VCrc32___024root.h"

// FUNCTIONS
VCrc32__Syms::~VCrc32__Syms()
{
}

VCrc32__Syms::VCrc32__Syms(VerilatedContext* contextp, const char* namep, VCrc32* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}

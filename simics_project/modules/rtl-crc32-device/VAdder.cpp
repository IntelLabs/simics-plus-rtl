// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VAdder__pch.h"

//============================================================
// Constructors

VAdder::VAdder(sc_core::sc_module_name /* unused */)
    : VerilatedModel{*Verilated::threadContextp()}
    , vlSymsp{new VAdder__Syms(contextp(), name(), this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_a{vlSymsp->TOP.io_a}
    , io_b{vlSymsp->TOP.io_b}
    , io_c{vlSymsp->TOP.io_c}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    // Sensitivities on all clocks and combinational inputs
    SC_METHOD(eval);
    sensitive << clock;
    sensitive << reset;
    sensitive << io_a;
    sensitive << io_b;

}

//============================================================
// Destructor

VAdder::~VAdder() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VAdder___024root___eval_debug_assertions(VAdder___024root* vlSelf);
#endif  // VL_DEBUG
void VAdder___024root___eval_static(VAdder___024root* vlSelf);
void VAdder___024root___eval_initial(VAdder___024root* vlSelf);
void VAdder___024root___eval_settle(VAdder___024root* vlSelf);
void VAdder___024root___eval(VAdder___024root* vlSelf);

void VAdder::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAdder::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VAdder___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VAdder___024root___eval_static(&(vlSymsp->TOP));
        VAdder___024root___eval_initial(&(vlSymsp->TOP));
        VAdder___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VAdder___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VAdder::eventsPending() { return false; }

uint64_t VAdder::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

//============================================================
// Invoke final blocks

void VAdder___024root___eval_final(VAdder___024root* vlSelf);

VL_ATTR_COLD void VAdder::final() {
    VAdder___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VAdder::hierName() const { return vlSymsp->name(); }
const char* VAdder::modelName() const { return "VAdder"; }
unsigned VAdder::threads() const { return 1; }
void VAdder::prepareClone() const { contextp()->prepareClone(); }
void VAdder::atClone() const {
    contextp()->threadPoolpOnClone();
}

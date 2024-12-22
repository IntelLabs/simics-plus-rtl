// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VCrc32__pch.h"
#include "verilated_vcd_sc.h"

//============================================================
// Constructors

VCrc32::VCrc32(sc_core::sc_module_name /* unused */)
    : VerilatedModel{*Verilated::threadContextp()}
    , vlSymsp{new VCrc32__Syms(contextp(), name(), this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_cmd_valid{vlSymsp->TOP.io_cmd_valid}
    , io_resp_valid{vlSymsp->TOP.io_resp_valid}
    , io_mem_req_ready{vlSymsp->TOP.io_mem_req_ready}
    , io_mem_req_valid{vlSymsp->TOP.io_mem_req_valid}
    , io_mem_req_bits_is_read{vlSymsp->TOP.io_mem_req_bits_is_read}
    , io_mem_req_bits_size_in_bytes{vlSymsp->TOP.io_mem_req_bits_size_in_bytes}
    , io_mem_resp_valid{vlSymsp->TOP.io_mem_resp_valid}
    , io_busy{vlSymsp->TOP.io_busy}
    , io_cmd_bits_rs1{vlSymsp->TOP.io_cmd_bits_rs1}
    , io_cmd_bits_rs2{vlSymsp->TOP.io_cmd_bits_rs2}
    , io_resp_bits_data{vlSymsp->TOP.io_resp_bits_data}
    , io_mem_req_bits_addr{vlSymsp->TOP.io_mem_req_bits_addr}
    , io_mem_req_bits_data{vlSymsp->TOP.io_mem_req_bits_data}
    , io_mem_resp_bits_data{vlSymsp->TOP.io_mem_resp_bits_data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    // Sensitivities on all clocks and combinational inputs
    SC_METHOD(eval);
    sensitive << clock;
    sensitive << reset;
    sensitive << io_cmd_valid;
    sensitive << io_mem_req_ready;
    sensitive << io_mem_resp_valid;
    sensitive << io_cmd_bits_rs1;
    sensitive << io_cmd_bits_rs2;
    sensitive << io_mem_resp_bits_data;

}

//============================================================
// Destructor

VCrc32::~VCrc32() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VCrc32___024root___eval_debug_assertions(VCrc32___024root* vlSelf);
#endif  // VL_DEBUG
void VCrc32___024root___eval_static(VCrc32___024root* vlSelf);
void VCrc32___024root___eval_initial(VCrc32___024root* vlSelf);
void VCrc32___024root___eval_settle(VCrc32___024root* vlSelf);
void VCrc32___024root___eval(VCrc32___024root* vlSelf);

void VCrc32::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VCrc32::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VCrc32___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VCrc32___024root___eval_static(&(vlSymsp->TOP));
        VCrc32___024root___eval_initial(&(vlSymsp->TOP));
        VCrc32___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VCrc32___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VCrc32::eventsPending() { return false; }

uint64_t VCrc32::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

//============================================================
// Invoke final blocks

void VCrc32___024root___eval_final(VCrc32___024root* vlSelf);

VL_ATTR_COLD void VCrc32::final() {
    VCrc32___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VCrc32::hierName() const { return vlSymsp->name(); }
const char* VCrc32::modelName() const { return "VCrc32"; }
unsigned VCrc32::threads() const { return 1; }
void VCrc32::prepareClone() const { contextp()->prepareClone(); }
void VCrc32::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VCrc32::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VCrc32___024root__trace_decl_types(VerilatedVcd* tracep);

void VCrc32___024root__trace_init_top(VCrc32___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VCrc32___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCrc32___024root*>(voidSelf);
    VCrc32__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VCrc32___024root__trace_decl_types(tracep);
    VCrc32___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VCrc32___024root__trace_register(VCrc32___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VCrc32::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (!sc_core::sc_get_curr_simcontext()->elaboration_done()) {
        vl_fatal(__FILE__, __LINE__, name(), "VCrc32::trace() is called before sc_core::sc_start(). Run sc_core::sc_start(sc_core::SC_ZERO_TIME) before trace() to complete elaboration.");
    }if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VCrc32::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VCrc32___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}

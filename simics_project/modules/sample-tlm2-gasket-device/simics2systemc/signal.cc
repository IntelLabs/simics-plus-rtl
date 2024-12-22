// -*- mode: C++; c-file-style: "virtutech-c++" -*-

/*
  © 2013 Intel Corporation

  This software and the related documents are Intel copyrighted materials, and
  your use of them is governed by the express license under which they were
  provided to you ("License"). Unless the License provides otherwise, you may
  not use, modify, copy, publish, distribute, disclose or transmit this software
  or the related documents without Intel's prior written permission.

  This software and the related documents are provided as is, with no express or
  implied warranties, other than those that are expressly stated in the License.
*/

#include <simics/systemc/simics2systemc/signal.h>
#include <simics/systemc/adapter.h>
#include <simics/systemc/adapter_log_groups.h>
#include <simics/systemc/kernel_state_modifier.h>
#include <simics/systemc/null_simics_object_ref.h>
#include <simics/systemc/simics2systemc/null_signal.h>
#include <simics/systemc/simics2systemc/gasket.h>

#include <algorithm>
#include <string>

namespace simics {
namespace systemc {
namespace simics2systemc {

SignalBase::SignalBase()
    : simics_obj_(new NullConfObjectRef), gasket_(new NullSignal),
      simulation_(NULL), internal_(NULL) {
}

void SignalBase::init(iface::SimulationInterface *simulation,
                  InternalInterface *internal) {
    simulation_ = simulation;
    internal_ = internal;
}

void SignalBase::update(bool value) {
    if (!simulation_) {
        Adapter *adapter = static_cast<Adapter *>(
                SIM_object_data(*simics_obj_));
        simulation_ = adapter;
        assert(simulation_);
    }

    if (!internal_) {
        Adapter *adapter = static_cast<Adapter *>(SIM_object_data(
                *simics_obj_));
        internal_ = adapter->internal();
        assert(internal_);
    }

    {
        KernelStateModifier m(simulation_);
        *gasket_->output_pin() = value;
    }
    sc_core::sc_curr_proc_kind enter_process_kind =
        sc_core::sc_get_current_process_handle().proc_kind();


    if (sc_core::sc_get_status() == sc_core::SC_PAUSED) {
        simulation_->runDeltaPhase(0);
        internal_->process_stack()->waitForExitCondition(enter_process_kind);
    }
}

void SignalBase::validate_signal_level(bool raise) {
    sc_core::sc_signal<bool> *output_pin = gasket_->output_pin();
    if (*output_pin == raise) {
        // NOTE: logging error here may seem strange, but this is how the
        // Simics signal protocol has been specified. Any Simics device that
        // raise/lower twice is per definition violating the protocol and that
        // should be caught. Though the SC side probably does not understand
        // this at all, suggesting that we probably need a new Simics interface
        // to connect to sc_signal.
        SIM_LOG_ERROR(*simics_obj_, Log_Other,
                      "Signal '%s' already %s", output_pin->name(),
                      raise ? "raised" : "lowered");
    }
}

void SignalBase::set_pin(sc_core::sc_in<bool> *target_pin, bool initial_level,
                     const ConfObjectRef &obj) {
    set_pin(target_pin->name(), initial_level, obj);
    (*target_pin)(*gasket_->output_pin());
}

void SignalBase::set_pin(sc_core::sc_inout<bool> *target_pin,
                         bool initial_level,
                     const ConfObjectRef &obj) {
    set_pin(target_pin->name(), initial_level, obj);
    (*target_pin)(*gasket_->output_pin());
}

void SignalBase::set_pin(const char *target_pin_name, bool initial_level,
                     const ConfObjectRef &obj) {
    FATAL_ERROR_IF(!obj, "Must provide a valid Simics object");
    delete simics_obj_;
    simics_obj_ = new ConfObjectRef(obj);

    std::string name = "gasket_";
    name += target_pin_name;
    std::replace(name.begin(), name.end(), '.', '_');
    create_gasket(name.c_str());
    *gasket_->output_pin() = initial_level;
}

void SignalBase::create_gasket(sc_core::sc_module_name n) {
    delete gasket_;
    gasket_ = new GasketBase(n);
}

GasketInterface *SignalBase::gasket() {
    return gasket_;
}

SignalBase::~SignalBase() {
    delete simics_obj_;
    delete gasket_;
}

}  // namespace simics2systemc
}  // namespace systemc
}  // namespace simics

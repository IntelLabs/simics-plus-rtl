// -*- mode: C++; c-file-style: "virtutech-c++" -*-

/*
  © 2020 Intel Corporation

  This software and the related documents are Intel copyrighted materials, and
  your use of them is governed by the express license under which they were
  provided to you ("License"). Unless the License provides otherwise, you may
  not use, modify, copy, publish, distribute, disclose or transmit this software
  or the related documents without Intel's prior written permission.

  This software and the related documents are provided as is, with no express or
  implied warranties, other than those that are expressly stated in the License.
*/

#include <systemc>

#include <simics/simulator/sim-get-class.h>
#include <simics/systemc/iface/signal_simics_adapter.h>
#include <simics/systemc/iface/simics_adapter.h>
#include <simics/systemc/simics2systemc/signal_class.h>

#include <string>

namespace simics {
namespace systemc {
namespace simics2systemc {

void SignalClassBase::finalize() {
    // Avoid recursive calls to finalize_instance
    SIM_set_object_configured(obj());

    // Make sure the Adapter is configured
    simulation_ref_.require();
}

iface::ScVersionInterface *SignalClassBase::version() {
    return this;
}

void SignalClassBase::createGasket(iface::SimulationInterface *simulation) {
    setSimulation(simulation);
    sc_core::sc_object *object = sc_core::sc_find_object(
            signal_name_.c_str());
    if (!object) {
        SIM_LOG_ERROR(obj(), 0,
                      "No SystemC object %s", signal_name_.c_str());
        return;
    }

    if (auto *sc_in = dynamic_cast<sc_core::sc_in<bool> *>(object)) {
        gasket()->set_pin(sc_in, initial_level_, simics_object());
        return;
    }

    if (auto *sc_inout = dynamic_cast<sc_core::sc_inout<bool> *>(object)) {
        gasket()->set_pin(sc_inout, initial_level_, simics_object());
        return;
    }

    SIM_LOG_ERROR(obj(), 0,
                  "SystemC object %s is not of type "
                  "sc_core::sc_in<bool> or sc_core::sc_inout<bool>",
                  signal_name_.c_str());
}

conf_class_t *SignalClassNonSerializable::registerGasketClass(
        const char* class_name) {
    conf_class_t *cls = SIM_get_class(class_name);
    if (SIM_clear_exception() == SimExc_No_Exception) {
        return cls;
    }

    auto new_cls = make_class<SignalClassNonSerializable>(class_name,
        "a SystemC simics2systemc gasket class",
        "Class for binding Simics interface to SystemC Signal Gasket.");
    new_cls->add(iface::createAdapter<
                 iface::SignalSimicsAdapter<SignalClassNonSerializable>>());
    new_cls->add(Attribute("signal", "s",
                           "Name of the sc_in or sc_inout object the gasket"
                           " is connected to.",
                           ATTR_CLS_VAR(SignalClassNonSerializable,
                                        signal_name_),
                           Sim_Attr_Required));
    new_cls->add(Attribute("initial_level", "b",
                           "Initial level of the signal object.",
                           ATTR_CLS_VAR(SignalClassNonSerializable,
                                        initial_level_)));
    new_cls->add(Attribute("simulation", "o",
                           "Simics object implementing the SystemC Simulation"
                           " interface.",
                           ATTR_CLS_VAR(SignalClassNonSerializable,
                                        simulation_ref_),
                           Sim_Attr_Required));

    return SIM_get_class(class_name);
}

}  // namespace simics2systemc
}  // namespace systemc  // NOLINT
}  // namespace simics  // NOLINT

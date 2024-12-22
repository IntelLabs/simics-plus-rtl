// -*- mode: C++; c-file-style: "virtutech-c++" -*-

/*
  © 2024 Intel Corporation

  This software and the related documents are Intel copyrighted materials, and
  your use of them is governed by the express license under which they were
  provided to you ("License"). Unless the License provides otherwise, you may
  not use, modify, copy, publish, distribute, disclose or transmit this software
  or the related documents without Intel's prior written permission.

  This software and the related documents are provided as is, with no express or
  implied warranties, other than those that are expressly stated in the License.
*/

#if INTC_EXT && USE_SIMICS_CHECKPOINTING
#include <simics/systemc/iface/signal_simics_adapter.h>
#include <simics/systemc/iface/simics_adapter.h>
#include <simics/systemc/simics2systemc/signal_class.h>

namespace simics {
namespace systemc {
namespace simics2systemc {

SignalClassSerializable::SignalClassSerializable(ConfObjectRef o)
    : SignalClassBase(o), SignalGasketAdapter(&gasket_, this) {}

conf_class_t *SignalClassSerializable::registerGasketClass(
        const char* class_name) {
    conf_class_t *cls = SIM_get_class(class_name);
    if (SIM_clear_exception() == SimExc_No_Exception) {
        return cls;
    }

    auto new_cls = make_class<SignalClassSerializable>(class_name,
        "a SystemC simics2systemc gasket class",
        "Class for binding Simics interface to SystemC Signal Gasket.");
    new_cls->add(iface::createAdapter<
                 iface::SignalSimicsAdapter<SignalClassSerializable>>());
    new_cls->add(Attribute("signal", "s",
                           "Name of the sc_in or sc_inout object the gasket"
                           " is connected to.",
                           ATTR_CLS_VAR(SignalClassSerializable,
                                        signal_name_),
                           Sim_Attr_Required));
    new_cls->add(Attribute("initial_level", "b",
                           "Initial level of the signal object.",
                           ATTR_CLS_VAR(SignalClassSerializable,
                                        initial_level_)));
    new_cls->add(Attribute("simulation", "o",
                           "Simics object implementing the SystemC Simulation"
                           " interface.",
                           ATTR_CLS_VAR(SignalClassSerializable,
                                        simulation_ref_),
                           Sim_Attr_Required));

    return SIM_get_class(class_name);
}

}  // namespace simics2systemc
}  // namespace systemc  // NOLINT
}  // namespace simics  // NOLINT

#endif

// -*- mode: C++; c-file-style: "virtutech-c++" -*-

/*
  © 2014 Intel Corporation

  This software and the related documents are Intel copyrighted materials, and
  your use of them is governed by the express license under which they were
  provided to you ("License"). Unless the License provides otherwise, you may
  not use, modify, copy, publish, distribute, disclose or transmit this software
  or the related documents without Intel's prior written permission.

  This software and the related documents are provided as is, with no express or
  implied warranties, other than those that are expressly stated in the License.
*/

#ifndef SIMICS_SYSTEMC_SIMICS2SYSTEMC_SIGNAL_GASKET_ADAPTER_H
#define SIMICS_SYSTEMC_SIMICS2SYSTEMC_SIGNAL_GASKET_ADAPTER_H

#include <simics/systemc/context.h>
#include <simics/systemc/description_interface.h>
#include <simics/systemc/iface/signal_interface.h>
#include <simics/systemc/iface/simulation_interface.h>
#include <simics/systemc/simics2systemc/signal.h>

#include <string>
#include <vector>

namespace simics {
namespace systemc {
namespace simics2systemc {

/** Adapter for Signal gasket. */
class SignalGasketAdapter
    : public iface::SignalInterface,
      public DescriptionInterface<iface::SignalInterface> {
  public:
    SignalGasketAdapter(SignalInterface *signal,
                        iface::SimulationInterface *simulation)
        : signal_(signal),
          simulation_(simulation) {
    }

    void raise() override {
        simics::systemc::Context context(simulation_);
        signal_->raise();
    }
    void lower() override {
        simics::systemc::Context context(simulation_);
        signal_->lower();
    }
    std::vector<std::string> description(DescriptionType type) override {
        if (type != DESCRIPTION_TYPE_SIMICS2SYSTEMC)
            return {};

        auto *signal = dynamic_cast<simics2systemc::SignalBase *>(signal_);
        if (!signal)
            return {};

        auto gasket = signal->gasket();
        if (!gasket)
            return {};

        return {gasket->gasket_name(), gasket->output_pin()->name()};
    }

  private:
    SignalInterface *signal_;
    iface::SimulationInterface *simulation_;
};

}  // namespace simics2systemc
}  // namespace systemc
}  // namespace simics

#endif

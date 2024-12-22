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

#ifndef SIMICS_SYSTEMC_SIMICS2SYSTEMC_SIGNAL_CLASS_H
#define SIMICS_SYSTEMC_SIMICS2SYSTEMC_SIGNAL_CLASS_H


#include <simics/systemc/gasket_class_interface.h>
#include <simics/systemc/iface/simulation_interface.h>
#include <simics/systemc/simics2systemc/signal.h>
#include <simics/systemc/simics2systemc/signal_gasket_adapter.h>
#include <simics/systemc/simulation_interface_proxy.h>
#include <simics/systemc/version.h>

#include <string>

namespace simics {
namespace systemc {
namespace simics2systemc {

class SignalClassBase : public ConfObject,
                        public GasketClassInterface,
                        public Version,
                        public SimulationInterfaceProxy {
    friend class SignalClassNonSerializable;
    friend class SignalClassSerializable;

  public:
    explicit SignalClassBase(ConfObjectRef o)
        : ConfObject(o), initial_level_(false) {}
    void finalize() override;

    // GasketClassInterface
    iface::ScVersionInterface *version() override;
    void createGasket(iface::SimulationInterface *simulation) override;

  private:
    virtual SignalBase *gasket() {return nullptr;}

    std::string signal_name_;
    bool initial_level_;
    ConfObjectRef simulation_ref_;
};

class SignalClassNonSerializable : public SignalClassBase,
                                   public SignalGasketAdapter {
  public:
    explicit SignalClassNonSerializable(ConfObjectRef o)
        : SignalClassBase(o),
          SignalGasketAdapter(&gasket_, this) {}

    static conf_class_t *registerGasketClass(const char* class_name);

  private:
    SignalBase *gasket() override {
        return &gasket_;
    }

    SignalBase gasket_;
};

#if INTC_EXT && USE_SIMICS_CHECKPOINTING
class SignalClassSerializable : public SignalClassBase,
                                public SignalGasketAdapter {
  public:
    explicit SignalClassSerializable(ConfObjectRef o);

    static conf_class_t *registerGasketClass(const char* class_name);

  private:
    SignalBase *gasket() override {
        return &gasket_;
    }

    SignalSerializable gasket_;
};
using SignalClass = SignalClassSerializable;
#else
using SignalClass = SignalClassNonSerializable;
#endif
}  // namespace simics2systemc
}  // namespace systemc  // NOLINT
}  // namespace simics  // NOLINT

#endif

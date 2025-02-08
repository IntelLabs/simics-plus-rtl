/*
  © 2017 Intel Corporation

  This software and the related documents are Intel copyrighted materials, and
  your use of them is governed by the express license under which they were
  provided to you ("License"). Unless the License provides otherwise, you may
  not use, modify, copy, publish, distribute, disclose or transmit this software
  or the related documents without Intel's prior written permission.

  This software and the related documents are provided as is, with no express or
  implied warranties, other than those that are expressly stated in the License.
*/

// Adapter base class (i.e. the Simics object), etc...
#include <simics/systemc/systemc_library.h>
#include <simics/c++/devs/signal.h>
#include "c++/crc32_rtl-interface.h"
#include "c++/systemc/crc32_rtl-interface-gasket.h"
#include "c++/systemc/crc32_rtl-interface-simics-adapter.h"
#include <tlm>
#include <tlm_utils/simple_initiator_socket.h>
#include <tlm_utils/simple_target_socket.h>
// The SystemC TLM device being wrapped
#include "gasket-device.h"

#define CLASS_NAME "crc32_rtl_device"
#define CLASS_TYPE Adapter<GasketDevice>

namespace scl = simics::systemc;
// <add id="sample-tlm2-gasket-device/Adapter">
// <insert-until text="// EOF_GASKET_ADAPTER"/></add>
template <class TModel>
class Adapter : public simics::systemc::Adapter, public scl::simics2tlm::Crc32RtlGasketAdapter
{
public:
    explicit Adapter(simics::ConfObjectRef o)
        : simics::systemc::Adapter(o), Crc32RtlGasketAdapter(&crc32_device_, this), top_("top")
    {

        simics_io_busy_->set_pin(&top_.io_busy);
        simics_memory_space_->set_gasket(scl::tlm2simics::createGasket(
            &top_.phys_mem_socket_, o));
        crc32_device_.set_gasket(scl::simics2tlm::createGasket(
            &top_.crc32_device_socket_, o));
        systemc_reset_.set_pin(&top_.reset, false, o);
        top_.freq_hz_ptr = &freq_hz_;

        // Initalize to sane value
        freq_hz_ = 1 * 1000 * 1000;
    };

    static void init_class(simics::ConfClass *cls)
    {
        cls->add(simics::Attribute(
            "freq_hz", "i",
            "frequency of clock in HZ",
            ATTR_CLS_VAR(Adapter, freq_hz_)));
        cls->add(simics::Attribute(
            "phys_mem", "o",
            "Physical memory, for outgoing DMA transactions.",
            ATTR_CLS_VAR(Adapter, simics_memory_space_)));
        cls->add(simics::Attribute("io_busy", "o|n",
                                   "Interrupt target.",
                                   ATTR_CLS_VAR(Adapter, simics_io_busy_)));
        cls->add(scl::iface::createAdapter<
                 scl::iface::Crc32RtlSimicsAdapter<Adapter>>());

        auto port = simics::make_class<CLASS_TYPE::Port>(
            CLASS_NAME ".port", CLASS_NAME " port",
            CLASS_NAME " port");
        port->add(scl::iface::createAdapter<
                  scl::iface::SignalSimicsAdapter<CLASS_TYPE::Port>>());
        cls->add(port, "port.reset");
    }
    TModel &model() { return top_; }
    scl::Connector<scl::systemc2simics::Signal> simics_io_busy_;

    class Port : public simics::Port<CLASS_TYPE>,
                 public scl::simics2systemc::SignalGasketAdapter
    {
    public:
        explicit Port(simics::ConfObjectRef o)
            : simics::Port<CLASS_TYPE>(o),
              SignalGasketAdapter(&parent()->systemc_reset_, parent())
        {
        }
    };

private:
    TModel top_;
    scl::Connector<scl::tlm2simics::MemorySpace> simics_memory_space_;
    scl::simics2tlm::Crc32RtlDevice crc32_device_;
    scl::simics2systemc::Signal systemc_reset_;
    uint64_t freq_hz_;
};
// EOF_GASKET_ADAPTER

static void initializeDevice(void)
{
    auto cls = simics::make_class<CLASS_TYPE>(
        CLASS_NAME,
        "sample SystemC TLM2 device",
        "The <class>" CLASS_NAME "</class> is a Simics module"
        " encapsulating a SystemC TLM2-based simple device to demonstrate"
        " the use of the Simics SystemC Library.");
}

extern "C" void init_local(void)
{
    initializeDevice();
}

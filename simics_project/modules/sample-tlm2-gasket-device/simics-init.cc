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

#include <tlm>
#include <tlm_utils/simple_initiator_socket.h>
#include <tlm_utils/simple_target_socket.h>
// The SystemC TLM device being wrapped
#include "gasket-device.h"

namespace scl = simics::systemc;
// <add id="sample-tlm2-gasket-device/Adapter">
// <insert-until text="// EOF_GASKET_ADAPTER"/></add>
template<class TModel>
class Adapter : public simics::systemc::Adapter {
 public:
    explicit Adapter(simics::ConfObjectRef o)
        : simics::systemc::Adapter(o)
        , top_("top") {

        simics_memory_space_->set_gasket(scl::tlm2simics::createGasket(
                &top_.phys_mem_socket_, o));


        }

static void init_class(simics::ConfClass *cls) {
    printf("INIT!!!!!!!!!!!1\n");
    cls->add(simics::Attribute(
                     "phys_mem", "o",
                     "Physical memory, for outgoing DMA transactions.",
                     ATTR_CLS_VAR(Adapter, simics_memory_space_)));
}
 private:
    TModel top_;
    scl::Connector<scl::tlm2simics::MemorySpace> simics_memory_space_;
};
// EOF_GASKET_ADAPTER

#define CLASS_NAME "sample_tlm2_gasket_device"

static void initializeDevice(void) {
    auto cls = simics::make_class<Adapter<GasketDevice>>(
        CLASS_NAME,
        "sample SystemC TLM2 device",
        "The <class>" CLASS_NAME "</class> is a Simics module"
        " encapsulating a SystemC TLM2-based simple device to demonstrate"
        " the use of the Simics SystemC Library.");
}

extern "C" void init_local(void) {
    initializeDevice();
}

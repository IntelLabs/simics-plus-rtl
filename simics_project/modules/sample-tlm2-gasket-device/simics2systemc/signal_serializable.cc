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
#include <simics/systemc/simics2systemc/signal.h>
#include <simics/systemc/adapter.h>
#include <simics/systemc/adapter_log_groups.h>
#include <simics/systemc/kernel_state_modifier.h>
#include <simics/systemc/null_simics_object_ref.h>
#include <simics/systemc/simics2systemc/null_signal.h>
#include <simics/systemc/simics2systemc/gasket.h>

#include <algorithm>

namespace simics {
namespace systemc {
namespace simics2systemc {

SignalSerializable::SignalSerializable()
    : SignalBase() {}

void SignalSerializable::create_gasket(sc_core::sc_module_name n) {
    delete gasket_;
    gasket_ = new GasketSerializable(n);
}

}  // namespace simics2systemc
}  // namespace systemc
}  // namespace simics
#endif

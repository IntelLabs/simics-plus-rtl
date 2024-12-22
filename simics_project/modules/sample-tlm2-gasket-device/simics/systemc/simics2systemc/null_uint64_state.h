// -*- mode: C++; c-file-style: "virtutech-c++" -*-

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

#ifndef SIMICS_SYSTEMC_SIMICS2SYSTEMC_NULL_SIGNAL_H
#define SIMICS_SYSTEMC_SIMICS2SYSTEMC_NULL_SIGNAL_H


#include <simics/systemc/instance_counter.h>
#include <simics/systemc/simics2systemc/gasket_interface.h>

#include <string>

namespace simics {
namespace systemc {
namespace simics2systemc {

/**
 * Utility class that counts the number of instances. This class is used to
 * validate that all signal gaskets have been assigned before running the
 * simulation.
 */
class NullSignal : public GasketInterface,
                   public InstanceCounter<NullSignal> {
    virtual sc_core::sc_signal<bool> *output_pin() {
        return NULL;
    }
    std::string gasket_name() const override {
        return "NullSignal";
    }
};

}  // namespace simics2systemc
}  // namespace systemc
}  // namespace simics

#endif

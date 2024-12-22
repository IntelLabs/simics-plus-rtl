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

#include <boost/test/unit_test.hpp>

#include <systemc>

#include <simics/systemc/simics2systemc/signal.h>
#include <simics/systemc/simics2systemc/null_signal.h>

#include <vector>

#include "environment.h"
#include "mock/mock_simulation.h"

namespace scl = simics::systemc;

BOOST_AUTO_TEST_SUITE(TestSimics2SystemCSignal)

class TestDevice : public sc_core::sc_module {
  public:
    SC_CTOR(TestDevice) : in_("pin") {}
    sc_core::sc_in<bool> in_;
};

class TestEnvironment : public Environment {
  public:
    TestEnvironment() : obj_(simulation_.simics_object()) {
        signal_.init(&simulation_, &simulation_);
    }
    simics::ConfObjectRef obj_;
    scl::simics2systemc::SignalSerializable signal_;
};

class TestEnvironmentTwoGaskets : public TestEnvironment {
  public:
    TestEnvironmentTwoGaskets() {
        signal2_.init(&simulation_, &simulation_);
    }
    scl::simics2systemc::SignalSerializable signal2_;
};

BOOST_FIXTURE_TEST_CASE(testSetPin, TestEnvironment) {
    TestDevice device("TestDevice");

    BOOST_CHECK_EQUAL(scl::simics2systemc::NullSignal::instances(), 1);

    signal_.set_pin(&device.in_, false, obj_);
    BOOST_CHECK_EQUAL(scl::simics2systemc::NullSignal::instances(), 0);
}

BOOST_FIXTURE_TEST_CASE(testRaiseAndLowerSignal, TestEnvironment) {
    TestDevice device("TestDevice");
    signal_.set_pin(&device.in_, false, obj_);

    sc_core::sc_start(sc_core::SC_ZERO_TIME);
    BOOST_CHECK_EQUAL(device.in_.read(), false);

    signal_.raise();
    sc_core::sc_start(1, sc_core::SC_MS);

    BOOST_CHECK_EQUAL(device.in_.read(), true);

    signal_.lower();
    sc_core::sc_start(1, sc_core::SC_MS);

    BOOST_CHECK_EQUAL(device.in_.read(), false);
}

BOOST_FIXTURE_TEST_CASE(testNameOfGasket, TestEnvironment) {
    TestDevice device("TestNameOfGasket");
    signal_.set_pin(&device.in_, false, obj_);
    sc_core::sc_object *obj = sc_core::sc_find_object(
            "gasket_TestNameOfGasket_pin");
    BOOST_REQUIRE(obj != NULL);
}

BOOST_FIXTURE_TEST_CASE(testNameOfChildren, TestEnvironment) {
    TestDevice device("TestNameOfChildren");
    signal_.set_pin(&device.in_, false, obj_);
    sc_core::sc_object *obj = sc_core::sc_find_object(
            "gasket_TestNameOfChildren_pin");
    const std::vector<sc_core::sc_object*> &children
        = obj->get_child_objects();
    BOOST_REQUIRE_EQUAL(children.size(), 1);
    BOOST_CHECK_EQUAL(children[0]->name(),
                      "gasket_TestNameOfChildren_pin.output_pin");
}

BOOST_FIXTURE_TEST_CASE(testNameOfChildrenWithTwoGaskets,
                        TestEnvironmentTwoGaskets) {
    TestDevice device1("TestNameOfChildrenWithTwoGaskets1");
    TestDevice device2("TestNameOfChildrenWithTwoGaskets2");
    signal_.set_pin(&device1.in_, false, obj_);
    signal2_.set_pin(&device2.in_, false, obj_);
    std::string name = "gasket_TestNameOfChildrenWithTwoGaskets2_pin";
    sc_core::sc_object *obj = sc_core::sc_find_object(name.c_str());
    const std::vector<sc_core::sc_object*> &children
        = obj->get_child_objects();
    BOOST_REQUIRE_EQUAL(children.size(), 1);
    BOOST_CHECK_EQUAL(children[0]->name(), name + ".output_pin");
}

BOOST_AUTO_TEST_SUITE_END()

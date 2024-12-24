/*                                                              -*- C++ -*-

  © 2017 Intel Corporation

  This software and the related documents are Intel copyrighted materials, and
  your use of them is governed by the express license under which they were
  provided to you ("License"). Unless the License provides otherwise, you may
  not use, modify, copy, publish, distribute, disclose or transmit this software
  or the related documents without Intel's prior written permission.

  This software and the related documents are provided as is, with no express or
  implied warranties, other than those that are expressly stated in the License.
*/

#ifndef SAMPLE_TLM2_GASKET_DEVICE_GASKET_DEVICE_H
#define SAMPLE_TLM2_GASKET_DEVICE_GASKET_DEVICE_H

#include "VCrc32.h"
#include <verilated_vcd_c.h>
#include <verilated_vcd_sc.h>

#include <simics/systemc/simics2tlm/gasket_owner.h>
#include <simics/systemc/simics2tlm/extension_sender.h>
#include <simics/systemc/iface/extension.h>
#include <tlm_utils/simple_target_socket.h>
#include <tlm_utils/simple_initiator_socket.h>
#include <simics/systemc/context.h>
#include <simics/systemc/iface/simulation_interface.h>
#include <simics/systemc/simics2tlm/gasket_adapter.h>

class VerilatedVcdC;

class GasketDevice : public sc_core::sc_module
{
public:
  tlm_utils::simple_initiator_socket<GasketDevice> phys_mem_socket_;
  tlm_utils::simple_target_socket<GasketDevice> crc32_device_socket_;
  typedef tlm::tlm_generic_payload Payload;
  SC_CTOR(GasketDevice)
      : clock("clock"), reset("reset"), io_cmd_valid("io_cmd_valid"), io_resp_valid("io_resp_valid"), 
      io_mem_req_ready("io_mem_req_ready"), io_mem_req_valid("io_mem_req_valid"), io_mem_req_bits_is_read("io_mem_req_bits_is_read"), io_mem_req_bits_size_in_bytes("io_mem_req_bits_size_in_bytes"), io_mem_resp_valid("io_mem_resp_valid"), io_busy("io_busy"), io_cmd_bits_rs1("io_cmd_bits_rs1"), io_cmd_bits_rs2("io_cmd_bits_rs2"), io_resp_bits_data("io_resp_bits_data"), io_mem_req_bits_addr("io_mem_req_bits_addr"), io_mem_req_bits_data("io_mem_req_bits_data"), io_mem_resp_bits_data("io_mem_resp_bits_data"), phys_mem_socket_("phys_mem"), 
      crc32_device_socket_("crc32_device_socket"), crc32("crc32")
  {

    // Possible autogenerate connections
    crc32.clock(clock);
    crc32.reset(reset);
    crc32.io_cmd_valid(io_cmd_valid);
    crc32.io_resp_valid(io_resp_valid);
    crc32.io_mem_req_ready(io_mem_req_ready);
    crc32.io_mem_req_valid(io_mem_req_valid);
    crc32.io_mem_req_bits_is_read(io_mem_req_bits_is_read);
    crc32.io_mem_req_bits_size_in_bytes(io_mem_req_bits_size_in_bytes);
    crc32.io_mem_resp_valid(io_mem_resp_valid);
    crc32.io_busy(io_busy);
    crc32.io_cmd_bits_rs1(io_cmd_bits_rs1);
    crc32.io_cmd_bits_rs2(io_cmd_bits_rs2);
    crc32.io_resp_bits_data(io_resp_bits_data);
    crc32.io_mem_req_bits_addr(io_mem_req_bits_addr);
    crc32.io_mem_req_bits_data(io_mem_req_bits_data);
    crc32.io_mem_resp_bits_data(io_mem_resp_bits_data);

        crc32_device_socket_.register_b_transport(this, &GasketDevice::b_transport);
    // crc32.reset(reset);
    SC_THREAD(doClock);
    // SC_THREAD(doCommand);
    SC_THREAD(doHandleMemRequest);
    tfd = new VerilatedVcdC;
    io_mem_req_ready.write(true); // ready to accept memory requests
    // sensitive reset
  }

  void b_transport(Payload &trans, sc_core::sc_time &t);
  void sendRequest(uint64_t src, uint64_t dst, uint64_t size, bool blocking);

private:
  VerilatedVcdC *tfd = NULL; // trace file descriptor

  void doCommand();
  void doHandleMemRequest();
  void doClock();
  void readMem(void *buf, uint64_t addr, uint32_t count);
  void writeMem(void *buf, uint64_t addr, uint32_t count);
  void outboundTransaction(Payload *pl);
  void preparePayload(tlm::tlm_generic_payload *pl, uint32_t addr,
                      uint32_t count, void *buf);

  VCrc32 crc32;


  // Possible autogenerated signals
  sc_core::sc_signal<bool> clock;
  sc_core::sc_signal<bool> reset;

  sc_core::sc_signal<bool> io_cmd_valid;
  sc_core::sc_signal<uint64_t> io_cmd_bits_rs1;
  sc_core::sc_signal<uint64_t> io_cmd_bits_rs2;

  sc_core::sc_signal<bool> io_mem_req_ready;
  sc_core::sc_signal<bool> io_mem_req_valid;
  sc_core::sc_signal<uint64_t> io_mem_req_bits_addr;
  sc_core::sc_signal<bool> io_mem_req_bits_is_read;
  sc_core::sc_signal<uint32_t> io_mem_req_bits_size_in_bytes;
  sc_core::sc_signal<uint64_t> io_mem_req_bits_data;
  sc_core::sc_signal<bool> io_mem_resp_valid;
  sc_core::sc_signal<uint64_t> io_mem_resp_bits_data;

  sc_core::sc_signal<bool> io_resp_valid;
  sc_core::sc_signal<uint64_t> io_resp_bits_data;

  sc_core::sc_signal<bool> io_busy;
};

// EOF_GASKET_DEVICE

// <add id="sample-tlm2-gasket-device/gasket-vector-device">
// <insert-until text="// EOF_GASKET_VECTOR_DEVICE"/></add>

#endif

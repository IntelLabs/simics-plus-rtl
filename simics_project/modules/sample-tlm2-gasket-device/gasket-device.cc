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

#include "gasket-device.h"

#include "verilated.cpp"
#include "verilated_vcd_c.cpp"
#include "verilated_vcd_sc.cpp"
#include "verilated_threads.cpp"

void GasketDevice::doCommand()
{
  // while(true) {
  // sendRequest();
  //}
}

void GasketDevice::doHandleMemRequest()
{
  while (1)
  {
    wait(clock.posedge_event());
    if (!io_mem_req_valid.read())
    {
      io_mem_resp_valid.write(false);
      continue;
    }

    printf("Got a request\n");
    char buf[io_mem_req_bits_size_in_bytes.read()];
    if (io_mem_req_bits_is_read.read())
    {
      readMem(buf, io_mem_req_bits_addr.read(), io_mem_req_bits_size_in_bytes.read());
      io_mem_resp_bits_data.write(*(uint64_t *)buf);
      io_mem_resp_valid.write(true);
    }
    else
    {
      io_mem_resp_valid.write(false);
      wait(clock.posedge_event());

      *(uint64_t *)buf = io_mem_req_bits_data.read();
      writeMem(buf, io_mem_req_bits_addr.read(), io_mem_req_bits_size_in_bytes.read());
    }
  }
}

void GasketDevice::doClock()
{

  static int cycle_count = 0;
  Verilated::traceEverOn(true);
  crc32.trace(tfd, 99);
  tfd->open(("wave" + std::string(".vcd")).c_str());
  while (1)
  {
    wait(10, sc_core::SC_PS);
    clock.write(true);
    if (tfd)
    {
      tfd->dump(static_cast<vluint64_t>(2 * cycle_count++));
      tfd->flush();
    }
    wait(10, sc_core::SC_PS);
    clock.write(false);
    if (tfd)
    {
      tfd->dump(static_cast<vluint64_t>(2 * cycle_count++));
      tfd->flush();
    }
  }
}

void GasketDevice::readMem(void *buf, uint64_t addr, uint32_t count)
{
  std::ostringstream log;
  log << "ReadMem from " << std::hex << addr << ", size " << count;

  Payload pl;
  preparePayload(&pl, addr, count, buf);
  pl.set_read();
  outboundTransaction(&pl);
  log << std::hex << " data: " << *(uint64_t *)pl.get_data_ptr();
  std::cout << log.str();
}

void GasketDevice::writeMem(void *buf, uint64_t addr, uint32_t count)
{
  std::ostringstream log;
  log << "WriteMem to " << std::hex << addr << ", size " << count;

  Payload pl;
  preparePayload(&pl, addr, count, buf);
  pl.set_write();
  outboundTransaction(&pl);
  log << std::hex << " data: " << *(uint64_t *)pl.get_data_ptr();
  std::cout << log.str();
}

void GasketDevice::outboundTransaction(Payload *pl)
{
  sc_core::sc_time delay = sc_core::SC_ZERO_TIME;
  Payload dmi_pl;
  dmi_pl.deep_copy_from(*pl);

  phys_mem_socket_->b_transport(*pl, delay);
}

void GasketDevice::preparePayload(tlm::tlm_generic_payload *pl, uint32_t addr,
                                  uint32_t count, void *buf)
{
  pl->set_address(addr);
  pl->set_data_length(count);
  pl->set_data_ptr(static_cast<unsigned char *>(buf));
  pl->set_streaming_width(count);
}

void GasketDevice::sendRequest(uint64_t src, uint64_t dst, uint64_t size, bool blocking)
{
  printf("sendRequest(%x, %x, %x)\n", src, dst, size);
  wait(clock.posedge_event());
  io_cmd_valid.write(true);
  io_cmd_bits_rs1.write(src);
  io_cmd_bits_rs2.write(dst);
  wait(clock.posedge_event());
  io_cmd_valid.write(false);
  io_cmd_bits_rs1.write(0x0);
  while (false == io_resp_valid.read())
    wait(clock.posedge_event());
  io_cmd_valid.write(true);
  io_cmd_bits_rs2.write(size);
  wait(clock.posedge_event());
  io_cmd_valid.write(false);
  io_cmd_bits_rs1.write(0);
  io_cmd_bits_rs2.write(0);
  while (io_busy.read())
  {
    wait(clock.posedge_event());
  }
}

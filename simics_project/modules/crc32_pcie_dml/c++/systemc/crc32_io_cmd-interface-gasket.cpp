// Autogenerate this file with empty functions for user to fill in
#ifndef MODULES_CRC32_PCIE_DML_CPP_CRC32_PCIE_INTERFACE_GASKET_H
#define MODULES_CRC32_PCIE_DML_CPP_CRC32_PCIE_INTERFACE_GASKET_H

#include "c++/crc32_pcie-interface.h"
#include <simics/iface/interface-info.h>
#include <simics/utility.h> // get_interface
#include <simics/systemc/simics2tlm/gasket_owner.h>
#include <simics/systemc/simics2tlm/extension_sender.h>
#include <simics/systemc/simics2tlm/gasket_adapter.h>

namespace simics
{
  namespace systemc
  {
    namespace iface
    {

      bool Crc32IoCmdDeviceGasketAdapter::start_crc(unsigned int arg, unsigned int arg1, size_t arg2, bool blocking)
      {
        Context context(simulation_);
        printf("START_CRC!!!!\n");
        return crc32_pcie_->start_crc(arg, arg1, arg2, blocking);
      }

      bool Crc32IoCmdDevice::start_crc(unsigned int arg, unsigned int arg1, size_t arg2, bool blocking)
      {
        printf("start_crc in PcieDevice\n");
        iface::Transaction t = pool_.acquire();

        // Specific to the TLM-2.0 device
        uint64_t args[4] = {arg, arg1, arg2, blocking};
        unsigned char *data_ptr = (unsigned char *)args;
        t->set_data_ptr(data_ptr);
        t->set_data_length(sizeof(args));
        t->set_write();

        // iface::MapInfoExtension ext(info);
        // t->set_extension<iface::MapInfoExtension>(&ext);
        // t.extension()->set_transport_debug(SIM_get_mem_op_inquiry(mop));
        bool success = gasket_->trigger(&t);
        // t->clear_extension<iface::MapInfoExtension>();

        return false;
      };
    }
  }
}
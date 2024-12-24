// Autogenerate this file??
#ifndef MODULES_CRC32_PCIE_DML_CPP_CRC32_PCIE_INTERFACE_GASKET_H
#define MODULES_CRC32_PCIE_DML_CPP_CRC32_PCIE_INTERFACE_GASKET_H

#include "crc32_pcie-interface.h"
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

      class Crc32IoCmdDeviceInterface
      {
      public:
        virtual bool start_crc(unsigned int arg, unsigned int arg1, size_t arg2, bool blocking) = 0;
        virtual ~Crc32IoCmdDeviceInterface() {};
      };
    }

    namespace simics2tlm
    {

      class Crc32IoCmdDeviceGasketAdapter
          : public iface::Crc32IoCmdDeviceInterface,
            public GasketAdapter<iface::Crc32IoCmdDeviceInterface>
      {
      public:
        Crc32IoCmdDeviceGasketAdapter(iface::Crc32IoCmdDeviceInterface *crc32_pcie,
                                      iface::SimulationInterface *simulation)
            : crc32_pcie_(crc32_pcie), simulation_(simulation)
        {
        }

        bool start_crc(unsigned int arg, unsigned int arg1, size_t arg2, bool blocking);

        simics2tlm::GasketOwner *gasket_owner() const override
        {
          return dynamic_cast<simics2tlm::GasketOwner *>(crc32_pcie_);
        }

      private:
        iface::Crc32IoCmdDeviceInterface *crc32_pcie_;
        iface::SimulationInterface *simulation_;
      };

      class Crc32IoCmdDevice : public simics::systemc::iface::Crc32IoCmdDeviceInterface,
                               public GasketOwner
      {
      public:
        Crc32IoCmdDevice()
        {
          set_type();
        }
        bool start_crc(unsigned int arg, unsigned int arg1, size_t arg2, bool blocking);

      private:
        iface::TransactionPool pool_;
      };

    }
  }
}

#include "crc32_io_cmd-interface-gasket.cpp"

#endif
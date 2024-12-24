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

      class Crc32PcieDeviceInterface
      {
      public:
        virtual bool start_crc(unsigned int arg, unsigned int arg1, size_t arg2, bool blocking) = 0;
        virtual ~Crc32PcieDeviceInterface() {};
      };
    }

    namespace simics2tlm
    {

      class Crc32PcieDeviceGasketAdapter
          : public iface::Crc32PcieDeviceInterface,
            public GasketAdapter<iface::Crc32PcieDeviceInterface>
      {
      public:
        Crc32PcieDeviceGasketAdapter(iface::Crc32PcieDeviceInterface *crc32_pcie,
                                     iface::SimulationInterface *simulation)
            : crc32_pcie_(crc32_pcie), simulation_(simulation)
        {
        }
        bool start_crc(unsigned int arg, unsigned int arg1, size_t arg2, bool blocking)
        {
          Context context(simulation_);
          printf("START_CRC!!!!\n");
          return crc32_pcie_->start_crc(arg, arg1, arg2, blocking);
        }
        simics2tlm::GasketOwner *gasket_owner() const override
        {
          return dynamic_cast<simics2tlm::GasketOwner *>(crc32_pcie_);
        }

      private:
        iface::Crc32PcieDeviceInterface *crc32_pcie_;
        iface::SimulationInterface *simulation_;
      };

      class Crc32PcieDevice : public simics::systemc::iface::Crc32PcieDeviceInterface, 
      public GasketOwner
      {
      public:
        Crc32PcieDevice()
        {
          set_type();
        }
        bool start_crc(unsigned int arg, unsigned int arg1, size_t arg2, bool blocking)
        {
          printf("start_crc in PcieDevice\n");
          iface::Transaction t = pool_.acquire();

          // Specific to the TLM-2.0 device
          uint64_t args[4] = {arg, arg1, arg2, blocking};
          unsigned char *data_ptr = (unsigned char *)args;
          t->set_data_ptr(data_ptr);
          t->set_data_length(sizeof(args));
          t->set_write();

          //iface::MapInfoExtension ext(info);
          //t->set_extension<iface::MapInfoExtension>(&ext);
          //t.extension()->set_transport_debug(SIM_get_mem_op_inquiry(mop));
          bool success = gasket_->trigger(&t);
         // t->clear_extension<iface::MapInfoExtension>();

          return false;
        };
        private:
        iface::TransactionPool pool_;
      };

    }
  }
}

#include <simics/devs/signal.h>
#include <simics/systemc/iface/signal_interface.h>
#include <simics/systemc/iface/simics_adapter.h>

#include <string>
#include <vector>

namespace simics
{
  namespace systemc
  {
    namespace iface
    {

      /** Adapter for Simics signal interface. */
      template <typename TBase, typename TInterface = Crc32PcieDeviceInterface>
      class Crc32PcieSimicsAdapter : public SimicsAdapter<crc32_pcie_interface_t>
      {
      public:
        Crc32PcieSimicsAdapter()
            : SimicsAdapter<crc32_pcie_interface_t>(
                  CRC32_PCIE_INTERFACE, init_iface())
        {
        }

      protected:
        static bool start_crc(conf_object_t *obj, unsigned int arg, unsigned int arg1, size_t arg2, bool blocking)
        {
          printf("start_crc in simicsadapter\n");
          return adapter<TBase, TInterface>(obj)->start_crc(arg, arg1, arg2, blocking);
        }

      private:
        std::vector<std::string> description(conf_object_t *obj,
                                             DescriptionType type)
        {
          return descriptionBase<TBase, TInterface>(obj, type);
        }
        crc32_pcie_interface_t init_iface()
        {
          crc32_pcie_interface_t iface = {};
          iface.start_crc = start_crc;
          return iface;
        }
      };

    } // namespace iface
  } // namespace systemc
} // namespace simics

#endif
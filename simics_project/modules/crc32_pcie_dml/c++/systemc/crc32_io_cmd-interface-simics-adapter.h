// Autogenerate this file??
#include "crc32_io_cmd-interface-gasket.h"
#include "../crc32_pcie-interface.h"

#include <string>
#include <vector>

namespace simics
{
  namespace systemc
  {
    namespace iface
    {

      /** Adapter for Simics signal interface. */
      template <typename TBase, typename TInterface = simics::systemc::iface::Crc32IoCmdDeviceInterface>
      class Crc32IoCmdSimicsAdapter : public SimicsAdapter<crc32_pcie_interface_t>
      {
      public:
        Crc32IoCmdSimicsAdapter()
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
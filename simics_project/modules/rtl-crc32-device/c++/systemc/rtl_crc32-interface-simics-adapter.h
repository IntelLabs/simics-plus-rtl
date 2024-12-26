// Autogenerate this file??
#include "rtl_crc32-interface-gasket.h"
#include "../rtl_crc32-interface.h"

#include <string>
#include <vector>

namespace simics
{
  namespace systemc
  {
    namespace iface
    {

      /** Adapter for Simics signal interface. */
      template <typename TBase, typename TInterface = simics::systemc::iface::RtlCrc32SCInterface>
      class RtlCrc32SimicsAdapter : public SimicsAdapter<rtl_crc32_interface_t>
      {
      public:
        RtlCrc32SimicsAdapter()
            : SimicsAdapter<rtl_crc32_interface_t>(
                  RTL_CRC32_INTERFACE, init_iface())
        {
        }

      protected:
        static bool start_crc(conf_object_t *obj, unsigned int arg, unsigned int arg1, size_t arg2, bool blocking)
        {
          return adapter<TBase, TInterface>(obj)->start_crc(arg, arg1, arg2, blocking);
        }

      private:
        std::vector<std::string> description(conf_object_t *obj,
                                             DescriptionType type)
        {
          return descriptionBase<TBase, TInterface>(obj, type);
        }
        rtl_crc32_interface_t init_iface()
        {
          rtl_crc32_interface_t iface = {};
          iface.start_crc = start_crc;
          return iface;
        }
      };

    } // namespace iface
  } // namespace systemc
} // namespace simics
// Autogenerate this file??
#include "crc32_rtl-interface-gasket.h"
#include "../crc32_rtl-interface.h"

#include <string>
#include <vector>

namespace simics
{
  namespace systemc
  {
    namespace iface
    {

      /** Adapter for Simics signal interface. */
      template <typename TBase, typename TInterface = simics::systemc::iface::Crc32RtlSCInterface>
      class Crc32RtlSimicsAdapter : public SimicsAdapter<crc32_rtl_interface_t>
      {
      public:
        Crc32RtlSimicsAdapter()
            : SimicsAdapter<crc32_rtl_interface_t>(
                  CRC32_RTL_INTERFACE, init_iface())
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
        crc32_rtl_interface_t init_iface()
        {
          crc32_rtl_interface_t iface = {};
          iface.start_crc = start_crc;
          return iface;
        }
      };

    } // namespace iface
  } // namespace systemc
} // namespace simics
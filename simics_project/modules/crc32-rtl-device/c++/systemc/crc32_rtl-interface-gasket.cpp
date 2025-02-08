// Autogenerate this file with empty functions for user to fill in

namespace simics
{
  namespace systemc
  {
    namespace simics2tlm
    {

      bool Crc32RtlDevice::start_crc(unsigned int arg, unsigned int arg1, size_t arg2, bool blocking)
      {
        printf("start_crc in PcieDevice\n");
        iface::Transaction t = pool_.acquire();

        // Specific to the TLM-2.0 device
        uint64_t args[4] = {arg, arg1, arg2, blocking};
        unsigned char *data_ptr = (unsigned char *)args;
        t->set_data_ptr(data_ptr);
        t->set_data_length(sizeof(args));
        t->set_write();

        bool success = gasket_->trigger(&t);

        return false;
      };
    }
  }
}
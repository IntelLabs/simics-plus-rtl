// Autogenerate this file with empty functions for user to fill in

namespace simics
{
  namespace systemc
  {
    namespace simics2tlm
    {

      bool Crc32RtlGasketAdapter::start_crc(unsigned int arg, unsigned int arg1, size_t arg2, bool blocking)
      {
        Context context(simulation_);
        return iface_->start_crc(arg, arg1, arg2, blocking);
      }

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
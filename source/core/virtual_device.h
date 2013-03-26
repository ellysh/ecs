#ifndef VIRTUAL_DEVICE_H
#define VIRTUAL_DEVICE_H

#include "udp_connection.h"

namespace virt_dashboard
{

class ProgramOptions;

class VirtualDevice
{
public:
    VirtualDevice(ProgramOptions& options) : options_(options) {}
    virtual ~VirtualDevice() {}

    virtual void Start() = 0;
    void Initialize();

protected:
    ProgramOptions& options_;
    /* FIXME: Use the interface Connection class here */
    UdpConnection connection_;

    virtual void CreateProtocol() = 0;

private:
    void ConfigureConnection();
};

}

#endif

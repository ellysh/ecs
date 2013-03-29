#ifndef VIRTUAL_USO_H
#define VIRTUAL_USO_H

#include "virtual_device.h"
#include "macros.h"

namespace virt_dashboard
{

class ProtocolUso;

class VirtualUso : public VirtualDevice
{
public:
    VirtualUso(ProgramOptions& options) : VirtualDevice(options) {}
    virtual ~VirtualUso();

    virtual void Start();

protected:
    virtual void CreateProtocol();

private:
    ProtocolUso* protocol_;

    DISALLOW_COPY_AND_ASSIGN(VirtualUso)
};

}

#endif

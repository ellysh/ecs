#ifndef VIRTUAL_CONTROLLER_H
#define VIRTUAL_CONTROLLER_H

#include "virtual_device.h"

namespace ecs
{

class ProtocolController;

class VirtualController : public VirtualDevice
{
public:
    VirtualController(const ProgramOptions& options) : VirtualDevice(options) {}
    virtual ~VirtualController();

    virtual void Start();

protected:
    virtual void CreateProtocol();

private:
    ProtocolController* protocol_;

    DISALLOW_COPY_AND_ASSIGN(VirtualController)
};

}

#endif

#ifndef VIRTUAL_DEVICE_H
#define VIRTUAL_DEVICE_H

#include <stddef.h>

#include "connection.h"

namespace ecs
{

class ProgramOptions;

class VirtualDevice
{
public:
    VirtualDevice(ProgramOptions& options) : options_(options), connection_(NULL) {}
    virtual ~VirtualDevice() {}

    virtual void Start() = 0;
    void Initialize();

protected:
    ProgramOptions& options_;
    Connection* connection_;

    virtual void CreateProtocol() = 0;

private:
    void CreateConnection();
    void ConfigureConnection();
};

}

#endif

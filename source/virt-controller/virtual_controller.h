#ifndef VIRTUAL_CONTROLLER_H
#define VIRTUAL_CONTROLLER_H

#include "udp_connection.h"
#include "macros.h"

namespace virt_dashboard
{

class ProgramOptions;
class ProtocolController;

class VirtualController
{
public:
    VirtualController(ProgramOptions& options);
    ~VirtualController();

    void Start();

private:
    ProgramOptions& options_;
    UdpConnection connection_;
    ProtocolController* protocol_;

    void ConfigureConnection();
    void CreateProtocol();

    DISALLOW_COPY_AND_ASSIGN(VirtualController)
};

}

#endif

#ifndef VIRTUAL_USO_H
#define VIRTUAL_USO_H

#include "udp_connection.h"
#include "macros.h"

namespace virt_dashboard
{

class ProgramOptions;
class ProtocolUso;

class VirtualUso
{
public:
    VirtualUso(ProgramOptions& options);
    virtual ~VirtualUso();

    void Start();

private:
    ProgramOptions& options_;
    UdpConnection connection_;
    ProtocolUso* protocol_;

    void ConfigureConnection();
    void CreateProtocol();

    DISALLOW_COPY_AND_ASSIGN(VirtualUso)
};

}

#endif

#ifndef PROTOCOL_USO_H
#define PROTOCOL_USO_H

#include "host_parser.h"
#include "types_vdb.h"

namespace virt_dashboard
{

class ProtocolUso
{
public:
    ProtocolUso(HostParser::RequestMap& requests) : requests_(requests) {}

    ByteArray GetRequest();
    int GetDelay();
    void NextRequest();

private:
    HostParser::RequestMap requests_;
};

}

#endif

#ifndef PROTOCOL_HOST_H
#define PROTOCOL_HOST_H

#include "host_parser.h"
#include "types_ecs.h"

namespace ecs
{

class ProtocolHost
{
public:
    ProtocolHost(HostParser::RequestMap& requests) : requests_(requests) {}

    ByteArray GetRequest();
    int GetDelay();
    void NextRequest();

private:
    HostParser::RequestMap requests_;
};

}

#endif

#ifndef PROTOCOL_HOST_H
#define PROTOCOL_HOST_H

#include "host_parser.h"
#include "types_ecs.h"

namespace ecs
{

class ProtocolHost
{
public:
    ProtocolHost(const HostParser::RequestMap& requests) : requests_(requests) {}

    ByteArray GetRequest() const;
    int GetDelay() const;
    void NextRequest();

private:
    HostParser::RequestMap requests_;
};

}

#endif

#ifndef PROTOCOL_USO_H
#define PROTOCOL_USO_H

#include "uso_parser.h"
#include "types_vdb.h"

namespace virt_dashboard
{

class ProtocolUso
{
public:
    ProtocolUso(UsoParser::RequestMap& requests) : requests_(requests) {}

    ByteArray GetRequest();
    int GetDelay();
    void NextRequest();

private:
    UsoParser::RequestMap requests_;
};

}

#endif

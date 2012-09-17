#ifndef PROTOCOL_CONTROLLER_H
#define PROTOCOL_CONTROLLER_H

#include "controller_parser.h"
#include "types_vdb.h"

namespace virt_dashboard
{

class ProtocolController
{
public:
    ProtocolController(ControllerParser::AddressAnswerMap& answers) : answers_(answers) {}

    ByteArray GetAnswer(ByteArray request);

private:
    ControllerParser::AddressAnswerMap answers_;
};

}

#endif

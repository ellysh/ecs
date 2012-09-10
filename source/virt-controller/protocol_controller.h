#ifndef PROTOCOL_CONTROLLER_H
#define PROTOCOL_CONTROLLER_H

#include "controller_parser.h"
#include "types_vdb.h"

namespace virt_dashboard
{

class ProtocolController
{
public:
    ProtocolController(int rs_address, ControllerParser::AnswerMap answers) :
        rs_address_(rs_address), answers_(answers) {};

    ByteArray GetAnswer(ByteArray request);

private:
    int rs_address_;
    ControllerParser::AnswerMap answers_;
};

}

#endif

#ifndef PROTOCOL_CONTROLLER_H
#define PROTOCOL_CONTROLLER_H

#include "controller_parser.h"
#include "types_vdb.h"

namespace virt_dashboard
{

class ProtocolController
{
public:
    ProtocolController(int rs_address, ControllerParser::AnswerMap& answers);

    ByteArray GetAnswer(ByteArray request);

private:
    int rs_address_;
    ControllerParser::AnswerMap answers_;

    /* FIXME: Service request and answer are hack for current solution
     * with A20 controller protocol */
    ByteArray service_request_;
    ByteArray service_answer_;
};

}

#endif

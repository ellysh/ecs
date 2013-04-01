#ifndef PROTOCOL_CONTROLLER_H
#define PROTOCOL_CONTROLLER_H

#include "controller_parser.h"
#include "types_ecs.h"

namespace ecs
{

class ProtocolController
{
public:
    ProtocolController(const ControllerParser::AddressAnswerMap& answers) : answers_(answers) {}

    ByteArray GetAnswer(const ByteArray& request);
    bool IsAnswerExist(const ByteArray& request) const;
    void NextAnswer(const ByteArray& request);

private:
    ControllerParser::AddressAnswerMap answers_;
};

}

#endif

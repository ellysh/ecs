#ifndef CONTROLLER_PARSER_H
#define CONTROLLER_PARSER_H

#include <string>
#include <list>
#include <map>

#include "scenario_parser.h"
#include "types_ecs.h"

namespace virt_dashboard
{

class ControllerParser : public ScenarioParser
{
public:
    typedef std::list< std::pair<ByteArray, ByteArray> > AnswerMap;
    typedef std::map< Byte, AnswerMap > AddressAnswerMap;

public:
    ControllerParser(std::string filename);
    virtual ~ControllerParser() {}

    AddressAnswerMap& GetAnswers();

protected:
    virtual void ParseFileLine(std::string& line);

private:
    AddressAnswerMap answers_;
};

}

#endif

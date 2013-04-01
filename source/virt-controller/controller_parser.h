#ifndef CONTROLLER_PARSER_H
#define CONTROLLER_PARSER_H

#include <string>
#include <list>
#include <map>

#include "scenario_parser.h"
#include "types_ecs.h"

namespace ecs
{

class ControllerParser : public ScenarioParser
{
public:
    typedef std::list< std::pair<ByteArray, ByteArray> > AnswerMap;
    typedef std::map< Byte, AnswerMap > AddressAnswerMap;

public:
    ControllerParser(const std::string filename);
    virtual ~ControllerParser() {}

    AddressAnswerMap& GetAnswers() const;

protected:
    virtual void ParseFileLine(const std::string& line);

private:
    mutable AddressAnswerMap answers_;
};

}

#endif

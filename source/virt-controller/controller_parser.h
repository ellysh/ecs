#ifndef CONTROLLER_PARSER_H
#define CONTROLLER_PARSER_H

#include <string>
#include <list>

#include "scenario_parser.h"
#include "types_vdb.h"

namespace virt_dashboard
{

class ControllerParser : public ScenarioParser
{
public:
    typedef std::list< std::pair<ByteArray, ByteArray> > AnswerMap;

public:
    ControllerParser(std::string filename);
    virtual ~ControllerParser() {}

    AnswerMap& GetAnswers();

protected:
    virtual void ParseFileLine(std::string& line);

private:
    AnswerMap answers_;
};

}

#endif

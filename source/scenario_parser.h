#ifndef SCENARIO_PARSER_H
#define SCENARIO_PARSER_H

#include <string>
#include <list>

#include "types_vdb.h"

namespace virt_dashboard
{

class ScenarioParser
{
private:
    typedef std::list< std::pair<ByteArray, ByteArray> > AnswerMap;

public:
    ScenarioParser(std::string filename);

    ByteArray GetAnswer(ByteArray request);

private:
    AnswerMap answers_;

    void ParseFile(std::string& filename);
};

}

#endif

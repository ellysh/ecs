#ifndef SCENARIO_PARSER_H
#define SCENARIO_PARSER_H

#include <string>

#include "types_vdb.h"

namespace virt_dashboard
{

class ScenarioParser
{
public:
    virtual ~ScenarioParser() {}

protected:
    virtual void ParseFileLine(std::string& line) = 0;

    void ParseFile(std::string& filename);
};

}

#endif

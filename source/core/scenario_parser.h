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
    virtual void ParseFile(std::string& filename) = 0;
};

}

#endif

#ifndef SCENARIO_PARSER_H
#define SCENARIO_PARSER_H

#include <string>

#include "types_virt_dashboard.h"

namespace virt_dashboard
{

class ScenarioParser
{
public:
    ScenarioParser(std::string filename);

    ByteArray GetAnswer(ByteArray request);
};

}

#endif

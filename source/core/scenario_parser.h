#ifndef SCENARIO_PARSER_H
#define SCENARIO_PARSER_H

#include <string>

#include "types_ecs.h"

namespace ecs
{

class ScenarioParser
{
public:
    virtual ~ScenarioParser() {}

protected:
    virtual void ParseFileLine(const std::string& line) = 0;

    void ParseFile(const std::string& filename);

    static ByteArray ParseRequest(const std::string& request);
};

}

#endif

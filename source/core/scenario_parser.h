#ifndef SCENARIO_PARSER_H
#define SCENARIO_PARSER_H

#include <string>

#include "types_ecs.h"

namespace ecs
{

class ScenarioParser
{
public:
    ScenarioParser(const std::string filename) {}
    virtual ~ScenarioParser() {}

protected:
    static ByteArray ParseRequest(const std::string& request);

    virtual void ParseFileLine(const std::string& line) = 0;

    void ParseFile(const std::string& filename);
};

}

#endif

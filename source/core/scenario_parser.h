#ifndef SCENARIO_PARSER_H
#define SCENARIO_PARSER_H

#include <string>

#include "types_ecs.h"

namespace virt_dashboard
{

class ScenarioParser
{
public:
    virtual ~ScenarioParser() {}

    static Byte StringToByte(std::string input);
    static ByteArray StringToArray(std::string input, size_t start, size_t end);

protected:
    virtual void ParseFileLine(std::string& line) = 0;

    void ParseFile(std::string& filename);

    static ByteArray ParseRequest(std::string& request);
};

}

#endif

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
    typedef std::list< std::pair<ByteArray, int> > RequestMap;

public:
    ScenarioParser(std::string filename);

    ByteArray GetRequest();
    int GetDelay();
    void NextRequest();

private:
    RequestMap requests_;

    void ParseFile(std::string& filename);
};

}

#endif

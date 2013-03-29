#ifndef HOST_PARSER_H
#define HOST_PARSER_H

#include <string>
#include <list>

#include "scenario_parser.h"
#include "types_ecs.h"

namespace virt_dashboard
{

class HostParser : public ScenarioParser
{
public:
    typedef std::list< std::pair<ByteArray, int> > RequestMap;

public:
    HostParser(std::string filename);
    virtual ~HostParser() {}

    RequestMap& GetRequests();

protected:
    virtual void ParseFileLine(std::string& line);

private:
    RequestMap requests_;
};

}

#endif

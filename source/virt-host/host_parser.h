#ifndef HOST_PARSER_H
#define HOST_PARSER_H

#include <string>
#include <list>

#include "scenario_parser.h"
#include "types_ecs.h"

namespace ecs
{

class HostParser : public ScenarioParser
{
public:
    typedef std::list< std::pair<ByteArray, int> > RequestMap;

public:
    HostParser(const std::string filename);
    virtual ~HostParser() {}

    RequestMap& GetRequests() const;

protected:
    virtual void ParseFileLine(const std::string& line);

private:
    mutable RequestMap requests_;
};

}

#endif

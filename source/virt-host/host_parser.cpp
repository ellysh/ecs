#include "host_parser.h"

#include <boost/lexical_cast.hpp>

using namespace std;
using namespace ecs;

HostParser::HostParser(const string filename) : ScenarioParser(filename)
{
    ParseFile(filename);
}

int ParseDelay(const string delay)
{
    if ( delay.empty() )
        return 0;

    size_t start = delay.find("]") + 2;
    size_t end = delay.size();

    string result(delay.substr(start, end));

    return boost::lexical_cast<int>(result);
}

void HostParser::ParseFileLine(const string& line)
{
    ByteArray request = ParseRequest(line);
    int delay = ParseDelay(line);

    requests_.push_back(pair<ByteArray,int>(request, delay));
}

HostParser::RequestMap& HostParser::GetRequests() const
{
    return requests_;
}

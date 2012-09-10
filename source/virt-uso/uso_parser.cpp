#include "uso_parser.h"

#include <boost/lexical_cast.hpp>

using namespace std;
using namespace virt_dashboard;

UsoParser::UsoParser(string filename)
{
    ParseFile(filename);
}

int ParseDelay(string delay)
{
    if ( delay.empty() )
        return 0;

    size_t start = delay.find("]") + 2;
    size_t end = delay.size();

    string result(delay.substr(start, end));

    return boost::lexical_cast<int>(result);
}

void UsoParser::ParseFileLine(string& line)
{
    ByteArray request = ParseRequest(line);
    int delay = ParseDelay(line);

    requests_.push_back(pair<ByteArray,int>(request, delay));
}

UsoParser::RequestMap& UsoParser::GetRequests()
{
    return requests_;
}

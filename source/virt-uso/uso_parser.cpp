#include "uso_parser.h"

#include <iostream>
#include <boost/lexical_cast.hpp>

#include "functions_vdb.h"
#include "scenario_conclusion.h"

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

ByteArray UsoParser::GetRequest()
{
    if ( requests_.empty() )
        ScenarioConclusion::ExitSuccess();

    return requests_.front().first;
}

int UsoParser::GetDelay()
{
    return requests_.front().second;
}

void UsoParser::NextRequest()
{
    requests_.pop_front();
}

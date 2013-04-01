#include "scenario_parser.h"

#include <fstream>

#include "functions.h"

using namespace std;
using namespace ecs;

void ScenarioParser::ParseFile(const string& filename)
{
    ifstream file(filename.c_str());

    string line;
    while ( getline(file, line) )
    {
        if ( line.empty() )
            continue;

        if ( line[0] == '#' )
            continue;

        ParseFileLine(line);
    }
}

ByteArray ScenarioParser::ParseRequest(const string& request)
{
    size_t start = 1;
    size_t end = request.find("]");

    return StringToArray(request, start, end);
}

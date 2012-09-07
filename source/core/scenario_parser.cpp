#include "scenario_parser.h"

#include <fstream>

using namespace std;
using namespace virt_dashboard;

void ScenarioParser::ParseFile(string& filename)
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

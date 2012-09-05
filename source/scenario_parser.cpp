#include "scenario_parser.h"

#include <fstream>
#include <iostream>

using namespace std;
using namespace virt_dashboard;

ScenarioParser::ScenarioParser(string filename)
{
    ParseFile(filename);
}

void ScenarioParser::ParseFile(string& filename)
{
    /* FIXME: Implement this method */

    ifstream file(filename.c_str());

    string line;
    while ( getline(file, line) )
    {
        cout << line << endl;
    }
}

ByteArray ScenarioParser::GetAnswer(ByteArray request)
{
    /* FIXME: Implement this method */
    return ByteArray();
}

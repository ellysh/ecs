#include "scenario_parser.h"

#include <fstream>
#include <sstream>

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

ByteArray ScenarioParser::ParseRequest(string& request)
{
    if ( request.empty() )
        return ByteArray();

    size_t start = 1;
    size_t end = request.find("]");

    return StringToArray(request, start, end);
}

Byte StringToByte(string& input)
{
    int result;
    stringstream stream;
    stream << hex << input;
    stream >> result;

    return result;
}

ByteArray ScenarioParser::StringToArray(string input, size_t start, size_t end)
{
    if ( input.size() < end )
        return ByteArray();

    ByteArray result;
    string byte;
    for ( size_t i = start; i < end; i+=3 )
    {
        byte.append(1, input[i]);
        byte.append(1, input[i+1]);

        result.push_back(StringToByte(byte));

        byte.clear();
    }

    return result;
}

#include "scenario_parser.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
using namespace virt_dashboard;

ScenarioParser::ScenarioParser(string filename)
{
    ParseFile(filename);
}

Byte StringToByte(string& input)
{
    int result;
    stringstream stream;
    stream << hex << input;
    stream >> result;

    return result;
}

ByteArray ArrayFromString(string input, size_t start, size_t end)
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

ByteArray ParseRequest(string request)
{
    if ( request.empty() )
        return ByteArray();

    size_t start = 1;
    size_t end = request.find("]");

    return ArrayFromString(request, start, end);
}

ByteArray ParseAnswer(string answer)
{
    /* FIXME: Implement this method */
    return ByteArray();
}

void ScenarioParser::ParseFile(string& filename)
{
    ifstream file(filename.c_str());

    ByteArray request;
    ByteArray answer;
    string line;
    while ( getline(file, line) )
    {
        request = ParseRequest(line);
        answer = ParseAnswer(line);

        answers_.push_front(pair<ByteArray,ByteArray>(request, answer));
    }
}

ByteArray ScenarioParser::GetAnswer(ByteArray request)
{
    /* FIXME: Implement this method */
    return ByteArray();
}

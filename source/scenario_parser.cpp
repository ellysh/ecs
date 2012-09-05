#include "scenario_parser.h"

#include <fstream>
#include <iostream>

using namespace std;
using namespace virt_dashboard;

ScenarioParser::ScenarioParser(string filename)
{
    ParseFile(filename);
}

Byte StringToByte(string& value)
{
    int result;
    stringstream stream;
    stream << hex << value;
    stream >> result;

    return result;
}

ByteArray ParseRequest(string request)
{
    if ( request.empty() )
        return ByteArray();

    ByteArray result;
    string byte;
    size_t index_start = 1;
    size_t index_end = request.find("]");

    for ( size_t i = index_start; i < index_end; i+=3 )
    {
        byte.append(1, request[i]);
        byte.append(1, request[i+1]);

        result.push_back(StringToByte(byte));

        byte.clear();
    }

    return result;
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

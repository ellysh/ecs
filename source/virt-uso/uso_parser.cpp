#include "uso_parser.h"

#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <sstream>

#include <boost/lexical_cast.hpp>

#include "functions_vdb.h"
#include "scenario_conclusion.h"

using namespace std;
using namespace virt_dashboard;

UsoParser::UsoParser(string filename)
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

ByteArray StringToArray(string input, size_t start, size_t end)
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

    return StringToArray(request, start, end);
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

void UsoParser::ParseFile(string& filename)
{
    ifstream file(filename.c_str());

    ByteArray request;
    int delay;
    string line;
    while ( getline(file, line) )
    {
        if ( line.empty() )
            continue;

        if ( line[0] == '#' )
            continue;

        request = ParseRequest(line);
        delay = ParseDelay(line);

        requests_.push_back(pair<ByteArray,int>(request, delay));
    }
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

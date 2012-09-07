#include "controller_parser.h"

#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <sstream>

#include "functions_vdb.h"
#include "scenario_conclusion.h"

using namespace std;
using namespace virt_dashboard;

/* FIXME: Get RS-485 address from ProgramOptions object */
static const ByteArray kServiceRequest = { 0x31, 0x72, 0x21 };
static const ByteArray kServiceAnswer = { 0x31, 0x72, 0x21, 0x00, 0x00, 0x00, 0x00 };

ControllerParser::ControllerParser(string filename)
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

ByteArray ParseAnswer(string answer)
{
    if ( answer.empty() )
        return ByteArray();

    size_t start = answer.find_last_of("[") + 1;
    size_t end = answer.find_last_of("]");

    return StringToArray(answer, start, end);
}

void ControllerParser::ParseFile(string& filename)
{
    ifstream file(filename.c_str());

    ByteArray request;
    ByteArray answer;
    string line;
    while ( getline(file, line) )
    {
        if ( line.empty() )
            continue;

        if ( line[0] == '#' )
            continue;

        request = ParseRequest(line);
        answer = ParseAnswer(line);

        answers_.push_back(pair<ByteArray,ByteArray>(request, answer));
    }
}

ByteArray ControllerParser::GetAnswer(ByteArray request)
{
    if ( answers_.empty() )
        ScenarioConclusion::ExitSuccess();

    if ( request == kServiceRequest )
        return kServiceAnswer;

    cout << "ControllerParser::GetAnswer() - check = ";
    PrintByteArray(answers_.front().first);

    if ( answers_.front().first == request )
    {
        ByteArray result(answers_.front().second);
        answers_.pop_front();

        cout << "\tanswer = ";
        PrintByteArray(result);

        return result;
    }
    else
    {
        cout << "\tanswer = EMPTY" << endl;
        return ByteArray();
    }
}

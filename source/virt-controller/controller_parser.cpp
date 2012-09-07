#include "controller_parser.h"

#include <iostream>

#include "functions_vdb.h"
#include "scenario_conclusion.h"

using namespace std;
using namespace virt_dashboard;

/* FIXME: Get RS-485 address from ProgramOptions object */
static const ByteArray kServiceRequest = { 0x31, 0x72, 0x21 };
static const ByteArray kServiceAnswer = { 0x31, 0x72, 0x21, 0x00, 0x00, 0x00, 0x00 };

ControllerParser::ControllerParser(std::string filename)
{
    ParseFile(filename);
}

ByteArray ParseAnswer(string answer)
{
    if ( answer.empty() )
        return ByteArray();

    size_t start = answer.find_last_of("[") + 1;
    size_t end = answer.find_last_of("]");

    return ScenarioParser::StringToArray(answer, start, end);
}

void ControllerParser::ParseFileLine(string& line)
{
    ByteArray request(ScenarioParser::ParseRequest(line));
    ByteArray answer(ParseAnswer(line));

    answers_.push_back(pair<ByteArray,ByteArray>(request, answer));
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

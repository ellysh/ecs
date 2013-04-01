#include "controller_parser.h"

using namespace std;
using namespace ecs;

ControllerParser::ControllerParser(std::string filename)
{
    ParseFile(filename);
}

ByteArray ParseAnswer(string answer)
{
    size_t start = answer.find_last_of("[") + 1;
    size_t end = answer.find_last_of("]");

    return ScenarioParser::StringToArray(answer, start, end);
}

Byte GetAddress(string& input)
{
    return ScenarioParser::StringToByte(input.substr(1, 3));
}

void ControllerParser::ParseFileLine(string& line)
{
    ByteArray request(ScenarioParser::ParseRequest(line));
    ByteArray answer(ParseAnswer(line));
    Byte address = GetAddress(line);

    answers_[address].push_back(pair<ByteArray,ByteArray>(request, answer));
}

ControllerParser::AddressAnswerMap& ControllerParser::GetAnswers()
{
    return answers_;
}

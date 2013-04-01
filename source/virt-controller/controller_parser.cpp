#include "controller_parser.h"

#include "functions.h"

using namespace std;
using namespace ecs;

ControllerParser::ControllerParser(const std::string filename) : ScenarioParser(filename)
{
    ParseFile(filename);
}

ByteArray ParseAnswer(const string answer)
{
    size_t start = answer.find_last_of("[") + 1;
    size_t end = answer.find_last_of("]");

    return StringToArray(answer, start, end);
}

Byte GetAddress(const string& input)
{
    return StringToByte(input.substr(1, 3));
}

void ControllerParser::ParseFileLine(const string& line)
{
    ByteArray request(ScenarioParser::ParseRequest(line));
    ByteArray answer(ParseAnswer(line));
    Byte address = GetAddress(line);

    answers_[address].push_back(pair<ByteArray,ByteArray>(request, answer));
}

ControllerParser::AddressAnswerMap& ControllerParser::GetAnswers() const
{
    return answers_;
}

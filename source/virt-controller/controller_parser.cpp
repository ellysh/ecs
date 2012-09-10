#include "controller_parser.h"

using namespace std;
using namespace virt_dashboard;

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

ControllerParser::AnswerMap& ControllerParser::GetAnswers()
{
    return answers_;
}

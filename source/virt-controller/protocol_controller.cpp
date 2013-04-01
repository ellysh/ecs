#include "protocol_controller.h"

#include <iostream>

#include "functions.h"
#include "scenario_conclusion.h"

using namespace std;
using namespace ecs;

Byte GetAddress(const ByteArray& request)
{
    return request[0];
}

ByteArray ProtocolController::GetAnswer(const ByteArray& request)
{
    Byte address = GetAddress(request);

    if ( answers_.count(address) == 0 )
        return ByteArray();

    cout << "ControllerParser::GetAnswer() - check = ";
    PrintByteArray(answers_[address].front().first);

    if ( answers_[address].front().first != request )
        return ByteArray();

    ByteArray result(answers_[address].front().second);

    cout << "\tanswer = ";
    PrintByteArray(result);

    return result;
}

void ProtocolController::NextAnswer(const ByteArray& request)
{
    Byte address = GetAddress(request);

    answers_[address].pop_front();

    if ( answers_[address].empty() )
        ScenarioConclusion::ExitSuccess();
}

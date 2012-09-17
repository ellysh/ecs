#include "protocol_controller.h"

#include <iostream>

#include "functions_vdb.h"
#include "scenario_conclusion.h"

using namespace std;
using namespace virt_dashboard;

Byte GetAddress(ByteArray& request)
{
    return request[0];
}

ByteArray ProtocolController::GetAnswer(ByteArray request)
{
    Byte address = GetAddress(request);

    if ( answers_.count(address) == 0 )
        return ByteArray();

    if ( answers_[address].empty() )
        ScenarioConclusion::ExitSuccess();

    cout << "ControllerParser::GetAnswer() - check = ";
    PrintByteArray(answers_[address].front().first);

    if ( answers_[address].front().first == request )
    {
        ByteArray result(answers_[address].front().second);
        answers_[address].pop_front();

        cout << "\tanswer = ";
        PrintByteArray(result);

        return result;
    }
    else
        return ByteArray();
}

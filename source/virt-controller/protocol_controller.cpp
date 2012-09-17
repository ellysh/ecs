#include "protocol_controller.h"

#include <iostream>

#include "functions_vdb.h"
#include "scenario_conclusion.h"

using namespace std;
using namespace virt_dashboard;

ByteArray ProtocolController::GetAnswer(ByteArray request)
{
    if ( answers_.empty() )
        ScenarioConclusion::ExitSuccess();

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

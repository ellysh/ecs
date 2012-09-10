#include "protocol_controller.h"

#include <iostream>

#include "functions_vdb.h"
#include "scenario_conclusion.h"

using namespace std;
using namespace virt_dashboard;

ProtocolController::ProtocolController(int rs_address, ControllerParser::AnswerMap& answers) :
        rs_address_(rs_address), answers_(answers)
{
    Byte code_address = 0x30 + (Byte)rs_address;
    service_request_ = { code_address, 0x72, 0x21 };
    service_answer_ = { code_address, 0x72, 0x21, 0x00, 0x00, 0x00, 0x00 };
}

ByteArray ProtocolController::GetAnswer(ByteArray request)
{
    if ( answers_.empty() )
        ScenarioConclusion::ExitSuccess();

    if ( request == service_request_ )
        return service_answer_;

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

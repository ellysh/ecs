#include "virtual_controller.h"

#include <iostream>

#include "program_options.h"
#include "option_names.h"
#include "controller_parser.h"
#include "protocol_controller.h"
#include "functions.h"

using namespace std;
using namespace ecs;

void VirtualController::CreateProtocol()
{
    ControllerParser parser(options_.GetString(kScenario));

    protocol_ = new ProtocolController(parser.GetAnswers());
}

VirtualController::~VirtualController()
{
    delete protocol_;
}

void VirtualController::Start()
{
    ByteArray request;
    ByteArray answer;

    while( true )
    {
        request = connection_->ReceiveData();

        if ( request.empty() )
            continue;

        cout << endl << GetTimeStamp() << "\trequest = ";
        PrintByteArray(request);

        answer = protocol_->GetAnswer(request);

        if ( answer.empty() )
        {
            cout << "\tanswer = EMPTY" << endl;
            continue;
        }

        cout << "\tanswer = ";
        PrintByteArray(answer);

        connection_->SendData(answer);

        if ( ! options_.IsExist(kCycleMode) )
            protocol_->NextAnswer(request);
    }
}

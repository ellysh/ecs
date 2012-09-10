#include "virtual_controller.h"

#include <iostream>

#include "program_options.h"
#include "udp_connection.h"
#include "controller_parser.h"
#include "protocol_controller.h"
#include "functions_vdb.h"

using namespace std;
using namespace virt_dashboard;

static const int kReceiveDelay = 2 * 1000;
static const int kAnswerDelay = 1;

void VirtualController::Start()
{
    /* FIXME: Split this method to submethods */
    UdpConnection connection;
    connection.SetLocalPoint(options_.GetString(kIpLocal),
                             options_.GetInt(kPortLocal));
    connection.SetRemotePoint(options_.GetString(kIpRemote),
                              options_.GetInt(kPortRemote));

    ControllerParser* parser = new ControllerParser(options_.GetString(kScenario));

    ProtocolController protocol(options_.GetInt(kRsAddress),
                                parser->GetAnswers());

    delete parser;

    ByteArray request;
    ByteArray answer;

    while( true )
    {
        usleep(kReceiveDelay);
        request = connection.ReceiveData();

        if ( request.empty() )
            continue;

        cout << "main()" << endl;
        cout << "\trequest = ";
        PrintByteArray(request);

        usleep(kAnswerDelay);
        answer = protocol.GetAnswer(request);

        cout << "\tanswer = ";
        PrintByteArray(answer);

        connection.SendData(answer);
    }
}

#include "virtual_controller.h"

#include <iostream>

#include "program_options.h"
#include "udp_connection.h"
#include "controller_parser.h"
#include "functions_vdb.h"

using namespace std;
using namespace virt_dashboard;

static const int kReceiveDelay = 2 * 1000;
static const int kAnswerDelay = 1;

void VirtualController::Start()
{
    UdpConnection connection;
    connection.SetLocalPoint(options_.GetString(kIpLocal),
                             options_.GetInt(kPortLocal));
    connection.SetRemotePoint(options_.GetString(kIpRemote),
                              options_.GetInt(kPortRemote));

    ControllerParser parser(options_.GetString(kScenario));

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
        answer = parser.GetAnswer(request);

        cout << "\tanswer = ";
        PrintByteArray(answer);

        connection.SendData(answer);
    }
}

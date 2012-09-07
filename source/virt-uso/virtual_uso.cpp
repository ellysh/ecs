#include "virtual_uso.h"

#include <iostream>

#include "program_options.h"
#include "udp_connection.h"
#include "scenario_parser.h"
#include "functions_vdb.h"

using namespace std;
using namespace virt_dashboard;

void VirtualUso::Start()
{
    UdpConnection connection;
    connection.SetLocalPoint(options_.GetString(kIpLocal),
                             options_.GetInt(kPortLocal));
    connection.SetRemotePoint(options_.GetString(kIpRemote),
                              options_.GetInt(kPortRemote));

    ScenarioParser parser(options_.GetString(kScenario));

    ByteArray request;

    while( true )
    {
        request = parser.GetRequest();

        if ( request.empty() )
            continue;

        cout << "main()" << endl;
        cout << "\trequest = ";
        PrintByteArray(request);

        connection.SendData(request);

        cout << "\tdelay = " << dec << parser.GetDelay() << endl;
        usleep(parser.GetDelay() * 1000);

        parser.NextRequest();
    }
}

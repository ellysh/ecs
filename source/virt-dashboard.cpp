#include <string>
#include <iostream>

#include "program_options.h"
#include "udp_connection.h"
#include "scenario_parser.h"

using namespace std;
using namespace virt_dashboard;

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    ProgramOptions options(argc, argv);

    if ( ! options.IsComplete() )
    {
        cout << options.GetDescription() << "\n";
        return 1;
    }

    UdpConnection connection;
    connection.SetLocalPoint(options.GetString(kIpLocal),
                             options.GetInt(kPort));
    connection.SetRemotePoint(options.GetString(kIpRemote),
                              options.GetInt(kPort));

    ScenarioParser parser(options.GetString(kScenario));

    ByteArray request;

    while( true )
    {
        request = connection.ReceiveData();

        connection.SendData(parser.GetAnswer(request));
    }

    return 0;
}

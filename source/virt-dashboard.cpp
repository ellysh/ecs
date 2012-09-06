#include <string>
#include <iostream>

#include "program_options.h"
#include "udp_connection.h"
#include "scenario_parser.h"
#include "functions_vdb.h"

using namespace std;
using namespace virt_dashboard;

namespace po = boost::program_options;

static const int kReceiveDelay = 1;
static const int kAnswerDelay = 5 * 1000;

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

    return 0;
}

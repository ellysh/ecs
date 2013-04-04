#include <iostream>

#include "program_options.h"
#include "option_names.h"
#include "virtual_host.h"

using namespace std;
using namespace ecs;

void PrintUsage()
{
    cout << "Usage: virt-host [options]" << endl;
    cout << "Options:" << endl;
    cout << "\t--scenario FILE\t\tScenario file" << endl;
    cout << "\t--type [serial | udp]\tType of the connection" << endl;
    cout << "\t--ipl IP_ADDRESS\tUDP: local IP address" << endl;
    cout << "\t--ipr IP_ADDRESS\tUDP: remote IP address" << endl;
    cout << "\t--portl PORT\t\tUDP: local port" << endl;
    cout << "\t--portr PORT\t\tUDP: remote port" << endl;
    cout << "\t--dev FILE\t\tSerial: device file" << endl;
    cout << "\t--baud BAUD_RATE\tSerial: baud rate value" << endl;
    cout << "\t--help\t\t\tPrint this help" << endl << endl;
    cout << "Example of virtual host with `a20-test.vh` scenario file:" << endl;
    cout << "\tvirt-host --dev /tmp/ttyS0 --baud 57600 --scenario a20-test.vh --type serial" << endl << endl;

    exit(0);
}

#define CHECK_OPTION_EXIST(option) \
    if ( ! options.IsExist(option) ) \
        return false;

bool IsOptionsComplete(const ProgramOptions& options)
{
    /* FIXME: This function is the same as virtul-controller one*/

    CHECK_OPTION_EXIST(kScenario)
    CHECK_OPTION_EXIST(kConnectionType)

    if ( options.GetString(kConnectionType) == kConnectionUdp )
    {
        CHECK_OPTION_EXIST(kIpLocal)
        CHECK_OPTION_EXIST(kIpRemote)
        CHECK_OPTION_EXIST(kPortLocal)
        CHECK_OPTION_EXIST(kPortRemote)
    }
    else if ( options.GetString(kConnectionType) == kConnectionSerial )
    {
        CHECK_OPTION_EXIST(kDevFile)
        CHECK_OPTION_EXIST(kBaudRate)
    }

    return true;
}

int main(int argc, const char* argv[])
{
    ProgramOptions options(argv, argv + argc);

    if ( ! IsOptionsComplete(options) )
        PrintUsage();

    VirtualHost host(options);

    host.Initialize();

    host.Start();

    return 0;
}

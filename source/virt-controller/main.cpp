#include <iostream>

#include "program_options.h"
#include "virtual_controller.h"

using namespace std;
using namespace ecs;

void PrintUsage()
{
    cout << "Usage: virt-controller [options]" << endl;
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
    cout << "Example of virtual serial controller with `a20-test.vc` scenario file:" << endl;
    cout << "\tvirt-controller --dev /tmp/ttyS0 --baud 57600 --scenario a20-test.vc --type serial" << endl << endl;

    exit(0);
}

bool IsOptionsComplete()
{
    /* FIXME: Implement this method */
    return true;
}

int main(int argc, const char* argv[])
{
    ProgramOptions options(argv, argv + argc);

    if ( ! IsOptionsComplete() )
        PrintUsage();

    VirtualController controller(options);

    controller.Initialize();

    controller.Start();

    return 0;
}

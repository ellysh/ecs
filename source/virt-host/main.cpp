#include <iostream>

#include "program_options.h"
#include "virtual_host.h"

using namespace std;
using namespace virt_dashboard;

int main(int argc, const char* argv[])
{
    ProgramOptions options(argc, argv);

    if ( ! options.IsComplete() )
    {
        cout << options.GetDescription() << "\n";
        return 1;
    }

    VirtualHost host(options);

    host.Initialize();

    host.Start();

    return 0;
}

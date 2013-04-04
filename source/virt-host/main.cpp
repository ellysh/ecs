#include <iostream>

#include "program_options.h"
#include "virtual_host.h"

using namespace std;
using namespace ecs;

int main(int argc, const char* argv[])
{
    ProgramOptions options(argv, argv + argc);
#if 0
    if ( ! options.IsComplete() )
    {
        cout << options.GetDescription() << "\n";
        return 1;
    }
#endif
    VirtualHost host(options);

    host.Initialize();

    host.Start();

    return 0;
}

#include <iostream>

#include "program_options.h"
#include "virtual_controller.h"

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

    VirtualController controller(options);

    controller.Initialize();

    controller.Start();

    return 0;
}

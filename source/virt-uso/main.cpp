#include <iostream>

#include "program_options.h"
#include "virtual_uso.h"

using namespace std;
using namespace virt_dashboard;

int main(int argc, char* argv[])
{
    ProgramOptions options(argc, argv);

    if ( ! options.IsComplete() )
    {
        cout << options.GetDescription() << "\n";
        return 1;
    }

    VirtualUso uso(options);

    uso.Start();

    return 0;
}

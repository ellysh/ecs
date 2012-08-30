#include <string>
#include <iostream>

#include "program_options.h"

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

    return 0;
}

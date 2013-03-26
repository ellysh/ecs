#include "program_options.h"

#include <iostream>
#include <boost/program_options/parsers.hpp>

#include "scenario_conclusion.h"

using namespace std;
using namespace virt_dashboard;

namespace po = boost::program_options;

static const int kErrorValue = -1;

ProgramOptions::ProgramOptions(const int argc, const char* argv[])
{
    description_ = new po::options_description("Allowed options");
    description_->add_options()
        (kHelp.c_str(), "produce help message")
        (kIpLocal.c_str(), po::value<string>(), "UDP: local IP address")
        (kIpRemote.c_str(), po::value<string>(), "UDP: remote IP address")
        (kPortLocal.c_str(), po::value<int>(), "UDP: local port")
        (kPortRemote.c_str(), po::value<int>(), "UDP: remote port")
        (kDevFile.c_str(), po::value<string>(), "Serial: device file")
        (kBaudRate.c_str(), po::value<int>(), "Serial: baud rate")
        (kScenario.c_str(), po::value<string>(), "scenario file");

    try
    {
        po::store(po::parse_command_line(argc, argv, *description_),
                  options_);
    }
    catch(...)
    {
        cout << GetDescription() << "\n";
        ScenarioConclusion::Exit();
    }
}

ProgramOptions::~ProgramOptions()
{
    delete description_;
}

string ProgramOptions::GetString(const string option_name) const
{
    if ( options_.count(option_name) == 0 )
        return string();

    return options_[option_name].as<string>();
}

int ProgramOptions::GetInt(const string option_name) const
{
    if ( options_.count(option_name) == 0 )
        return kErrorValue;

    return options_[option_name].as<int>();
}

bool ProgramOptions::IsComplete() const
{
    /* FIXME: Refactoring this method with MACROS */
    if ( options_.count(kHelp) != 0 )
        return false;

    if ( GetString(kIpLocal).empty() )
        return false;

    if ( GetString(kIpRemote).empty() )
        return false;

    if ( GetString(kScenario).empty() )
        return false;

    if ( GetInt(kPortLocal) == kErrorValue )
        return false;

    if ( GetInt(kPortRemote) == kErrorValue )
        return false;

    return true;
}

po::options_description& ProgramOptions::GetDescription() const
{
    return *description_;
}

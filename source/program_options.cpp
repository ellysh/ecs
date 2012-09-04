#include "program_options.h"

#include <boost/program_options/parsers.hpp>

using namespace std;
using namespace virt_dashboard;

namespace po = boost::program_options;

static const string kHelp = "help";
static const string kIpLocal = "ipl";
static const string kIpRemote = "ipr";
static const string kPort = "port";
static const string kRsAddress = "rs";

static const int kErrorValue = -1;

ProgramOptions::ProgramOptions(int argc, char* argv[])
{
    description_ = new po::options_description("Allowed options");
    description_->add_options()
        (kHelp.c_str(), "produce help message")
        (kIpLocal.c_str(), po::value<string>(), "UDP connection local IP address")
        (kIpRemote.c_str(), po::value<string>(), "UDP connection remote IP address")
        (kPort.c_str(), po::value<int>(), "UDP connection port")
        (kRsAddress.c_str(), po::value<int>(), "RS-485 connection address");

    po::store(po::parse_command_line(argc, argv, *description_),
              options_);
}

ProgramOptions::~ProgramOptions()
{
    delete description_;
}

string ProgramOptions::GetString(string option_name)
{
    if ( options_.count(option_name) == 0 )
        return string();

    return options_[option_name].as<string>();
}

int ProgramOptions::GetInt(string option_name)
{
    if ( options_.count(option_name) == 0 )
        return kErrorValue;

    return options_[option_name].as<int>();
}

bool ProgramOptions::IsComplete()
{
    if ( ! GetString(kHelp).empty() )
        return false;

    if ( GetString(kIpLocal).empty() )
        return false;

    if ( GetString(kIpRemote).empty() )
        return false;

    if ( GetInt(kPort) == kErrorValue )
        return false;

    if ( GetInt(kRsAddress) == kErrorValue )
        return false;

    return true;
}

po::options_description& ProgramOptions::GetDescription()
{
    return *description_;
}

#include "program_options.h"

#include <iostream>
#include <boost/program_options/parsers.hpp>

#include "scenario_conclusion.h"

using namespace std;
using namespace ecs;

namespace po = boost::program_options;

static const int kErrorValue = -1;

ProgramOptions::ProgramOptions(const int argc, const char* argv[])
{
    description_ = new po::options_description("Allowed options");
    description_->add_options()
        (kHelp.c_str(), "produce help message")
        (kConnectionType.c_str(), po::value<string>(), "Type of the connection (`serial` or `udp`)")
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
    if ( GetBool(option_name) )
        return options_[option_name].as<string>();
    else
        return string();
}

int ProgramOptions::GetInt(const string option_name) const
{
    if ( GetBool(option_name) )
        return options_[option_name].as<int>();
    else
        return kErrorValue;
}

bool ProgramOptions::GetBool(const std::string option_name) const
{
    if ( options_.count(option_name) != 0 )
        return true;
    else
        return false;
}

#define CHECK_EMPTY(option) \
    if ( GetString(option).empty() ) \
        return false;

#define CHECK_ERROR_VALUE(option) \
    if ( GetInt(option) == kErrorValue ) \
        return false;

bool ProgramOptions::IsComplete() const
{
    if ( GetBool(kHelp) )
        return false;

    CHECK_EMPTY(kConnectionType)

    if ( GetString(kConnectionType) == kConnectionUdp )
    {
        CHECK_EMPTY(kIpLocal)
        CHECK_EMPTY(kIpRemote)
        CHECK_ERROR_VALUE(kPortLocal)
        CHECK_ERROR_VALUE(kPortRemote)
    }
    else if ( GetString(kConnectionType) == kConnectionSerial )
    {
        CHECK_EMPTY(kDevFile)
        CHECK_ERROR_VALUE(kBaudRate)
    }

    CHECK_EMPTY(kScenario)

    return true;
}

po::options_description& ProgramOptions::GetDescription() const
{
    return *description_;
}

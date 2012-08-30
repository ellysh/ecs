#include "program_options.h"

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>

using namespace std;
namespace po = boost::program_options;

ProgramOptions::ProgramOptions(int argc, char* argv[])
{
    po::options_description description("Allowed options");
    description.add_options()
        ("help", "produce help message")
        ("ip,i", po::value<string>(), "UDP connection IP address")
        ("port,p", po::value<int>(), "UDP connection port")
        ("rs,r", po::value<int>(), "RS-485 connection address");

    po::store(po::parse_command_line(argc, argv, description),
              options_);
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
        return 0;

    return options_[option_name].as<int>();
}

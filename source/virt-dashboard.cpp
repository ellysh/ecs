#include <string>
#include <iostream>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    po::options_description description("Allowed options");
    description.add_options()
        ("help", "produce help message")
        ("ip,i", po::value<string>(), "UDP connection IP address")
        ("port,p", po::value<int>(), "UDP connection port")
        ("rs,r", po::value<int>(), "RS-485 connection address");

    po::variables_map variables;
    po::store(po::parse_command_line(argc, argv, description),
              variables);

    if (variables.count("help"))
    {
        cout << description << "\n";
        return 1;
    }

    if (variables.count("ip"))
    {
        cout << "UDP connection IP was set to " << variables["ip"].as<string>() << ".\n";
    } else
    {
        cout << "UDP connection IP was not set.\n";
    }

    return 0;
}

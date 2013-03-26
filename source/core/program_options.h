#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

#include <string>

#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/options_description.hpp>

namespace po = boost::program_options;

namespace virt_dashboard
{

static const std::string kHelp = "help";
static const std::string kIpLocal = "ipl";
static const std::string kIpRemote = "ipr";
static const std::string kPortLocal = "portl";
static const std::string kPortRemote = "portr";
static const std::string kScenario = "scenario";
static const std::string kDevFile = "dev";
static const std::string kBaudRate = "baud";

class ProgramOptions
{
public:
    ProgramOptions(const int argc, const char* argv[]);
    ~ProgramOptions();

    std::string GetString(const std::string option_name) const;
    int GetInt(const std::string option_name) const;
    po::options_description& GetDescription() const;
    bool IsComplete() const;

private:
    po::variables_map options_;
    po::options_description* description_;
};

}

#endif

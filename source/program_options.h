#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

#include <string>

#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/options_description.hpp>

namespace po = boost::program_options;

namespace virt_dashboard
{

class ProgramOptions
{
public:
    ProgramOptions(int argc, char* argv[]);
    ~ProgramOptions();

    std::string GetString(std::string option_name);
    int GetInt(std::string option_name);
    po::options_description& GetDescription();
    bool IsComplete();

private:
    po::variables_map options_;
    po::options_description* description_;
};

}

#endif

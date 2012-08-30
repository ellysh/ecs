#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

#include <string>

#include <boost/program_options/variables_map.hpp>

namespace po = boost::program_options;

class ProgramOptions
{
public:
    ProgramOptions(int argc, char* argv[]);

    std::string GetString(std::string option_name);
    int GetInt(std::string option_name);

private:
    po::variables_map options_;
};

#endif

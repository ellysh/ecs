#ifndef OPTION_NAMES_H
#define OPTION_NAMES_H

#include <string>

namespace ecs
{

static const std::string kHelp = "--help";
static const std::string kIpLocal = "--ipl";
static const std::string kIpRemote = "--ipr";
static const std::string kPortLocal = "--portl";
static const std::string kPortRemote = "--portr";
static const std::string kScenario = "--scenario";
static const std::string kDevFile = "--dev";
static const std::string kBaudRate = "--baud";
static const std::string kConnectionType = "--type";
static const std::string kCycleMode = "--cycle";
static const std::string kTimeout = "--timeout";

static const std::string kConnectionSerial = "serial";
static const std::string kConnectionUdp = "udp";

}

#endif

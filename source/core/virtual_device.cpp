#include "virtual_device.h"

#include "program_options.h"

using namespace std;
using namespace virt_dashboard;

void VirtualDevice::Initialize()
{
    ConfigureConnection();

    CreateProtocol();
}

void VirtualDevice::ConfigureConnection()
{
    connection_.SetLocalPoint(options_.GetString(kIpLocal),
                              options_.GetInt(kPortLocal));
    connection_.SetRemotePoint(options_.GetString(kIpRemote),
                               options_.GetInt(kPortRemote));
}

#include "virtual_device.h"

#include <assert.h>

#include "program_options.h"
#include "option_names.h"
#include "serial_connection.h"
#include "udp_connection.h"

using namespace std;
using namespace ecs;

void VirtualDevice::Initialize()
{
    CreateConnection();

    ConfigureConnection();

    CreateProtocol();
}

void VirtualDevice::CreateConnection()
{
    string connection_type = options_.GetString(kConnectionType);

    if ( connection_type == kConnectionUdp )
        connection_ = new UdpConnection();
    else if ( connection_type == kConnectionSerial )
        connection_ = new SerialConnection();
    assert( connection_ != NULL );
}

void VirtualDevice::ConfigureConnection()
{
    connection_->Configure(options_);
}

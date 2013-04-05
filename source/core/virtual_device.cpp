#include "virtual_device.h"

#include <libserial/serial_connection.h>
#include <assert.h>

#include "connection_impl.h"
#include "udp_connection_impl.h"
#include "program_options.h"
#include "option_names.h"

using namespace std;
using namespace ecs;

void VirtualDevice::Initialize()
{
    CreateConnection();

    CreateProtocol();
}

void VirtualDevice::CreateUdpConnection()
{
    string address_local = options_.GetString(kIpLocal);
    int port_local = options_.GetInt(kPortLocal);

    string address_remote = options_.GetString(kIpRemote);
    int port_remote = options_.GetInt(kPortRemote);

    UdpConnectionImpl* udp_connection = new UdpConnectionImpl(address_local, port_local,
                                                              address_remote, port_remote);
    connection_ = new Connection(new ConnectionImpl(udp_connection));

    //timeout_ = options.GetInt(kTimeout);
}

void VirtualDevice::CreateSerialConnection()
{
    string dev_file = options_.GetString(kDevFile);
    int baud_rate = options_.GetInt(kBaudRate);

    serial::SerialConnection* serial_connection = new serial::SerialConnection(dev_file, baud_rate);
    connection_ = new Connection(new ConnectionImpl(serial_connection));

    //timeout_ = options.GetInt(kTimeout);
}

void VirtualDevice::CreateConnection()
{
    string connection_type = options_.GetString(kConnectionType);

    if ( connection_type == kConnectionUdp )
        CreateUdpConnection();
    else if ( connection_type == kConnectionSerial )
        CreateSerialConnection();

    assert( connection_ != NULL );
}

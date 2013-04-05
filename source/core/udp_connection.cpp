#include "udp_connection.h"

#include <iostream>
#include <boost/bind.hpp>

#include "program_options.h"
#include "option_names.h"

using namespace std;
using namespace ecs;

ByteArray UdpConnection::ReceiveData()
{
    /* FIXME: Implement this method */
}

void UdpConnection::SendData(const ByteArray& data)
{
    /* FIXME: Implement this method */
}

void UdpConnection::Configure(const ProgramOptions& options)
{
    if ( IsInit() )
        return;

    string address_local = options.GetString(kIpLocal);
    int port_local = options.GetInt(kPortLocal);

    string address_remote = options.GetString(kIpRemote);
    int port_remote = options.GetInt(kPortRemote);

    connection_ = new UdpConnectionImpl(address_local, port_local,
                                        address_remote, port_remote);
}

bool UdpConnection::IsInit() const
{
    if ( connection_ != NULL )
        return true;
    else
        return false;
}

#include "udp_connection.h"

#include "udp_connection_impl.h"
#include "connection_impl.h"
#include "program_options.h"
#include "option_names.h"

using namespace std;
using namespace ecs;

void UdpConnection::Configure(const ProgramOptions& options)
{
    if ( IsInit() )
        return;

    string address_local = options.GetString(kIpLocal);
    int port_local = options.GetInt(kPortLocal);

    string address_remote = options.GetString(kIpRemote);
    int port_remote = options.GetInt(kPortRemote);

    UdpConnectionImpl* udp_connection = new UdpConnectionImpl(address_local, port_local,
                                                              address_remote, port_remote);
    connection_ = new ConnectionImpl(udp_connection);

    timeout_ = options.GetInt(kTimeout);
}

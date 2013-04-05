#ifndef UDP_CONNECTION_H
#define UDP_CONNECTION_H

#include <string>
#include <boost/asio.hpp>

#include "connection.h"
#include "udp_connection_impl.h"
#include "types_ecs.h"

namespace ecs
{

class UdpConnection : public Connection
{
public:
    UdpConnection() : connection_(NULL) {};
    virtual ~UdpConnection();

    virtual ByteArray ReceiveData();
    virtual void SendData(const ByteArray& data);
    virtual void Configure(const ProgramOptions& options);

private:
    UdpConnectionImpl* connection_;

    /* FIXME: Move this method to parent class */
    bool IsInit() const;

    DISALLOW_COPY_AND_ASSIGN(UdpConnection)
};

}

#endif

#ifndef CONNECTION_IMPL_H
#define CONNECTION_IMPL_H

#include <string>

#include <libserial/serial_connection.h>

#include "types_ecs.h"

namespace ecs
{

class UdpConnectionImpl;

class ConnectionImpl
{
public:
    ConnectionImpl(serial::SerialConnection* connection);
    ConnectionImpl(UdpConnectionImpl* connection);

    void SendData(const ByteArray& data);
    ByteArray ReceiveData(const size_t size);

private:
    serial::SerialConnection* serial_connection_;
    UdpConnectionImpl* udp_connection_;
};

}

#endif

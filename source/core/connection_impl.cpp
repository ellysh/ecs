#include "connection_impl.h"

#include "udp_connection_impl.h"

using namespace ecs;

ConnectionImpl::ConnectionImpl(serial::SerialConnection* connection) : udp_connection_(NULL)
{
    serial_connection_ = connection;
}

ConnectionImpl::ConnectionImpl(UdpConnectionImpl* connection) : serial_connection_(NULL)
{
    udp_connection_ = connection;
}

void ConnectionImpl::SendData(const ByteArray& data)
{
    if ( serial_connection_ != NULL )
        serial_connection_->SendData(data);
    else if ( udp_connection_ != NULL )
        udp_connection_->SendData(data);
}

ByteArray ConnectionImpl::ReceiveData(const size_t size)
{
    if ( serial_connection_ != NULL )
        return serial_connection_->ReceiveData(size);
    else if ( udp_connection_ != NULL )
        return udp_connection_->ReceiveData(size);
    else
        return ByteArray();
}

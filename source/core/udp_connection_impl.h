#ifndef UDP_CONNECTION_IMPL_H
#define UDP_CONNECTION_IMPL_H

#include <string>
#include <boost/asio.hpp>

#include "types_ecs.h"

namespace ecs
{

class UdpConnectionImpl
{
public:
    UdpConnectionImpl(const std::string address_local, const int port_local,
                      const std::string address_remote, const int port_remote);

    void SendData(const ByteArray& data);
    ByteArray ReceiveData();

private:
    boost::asio::io_service io_service_;
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint remote_point_;

    void Connect(const std::string address, const int port);
    boost::asio::ip::udp::endpoint GetEndPoint(const std::string address, const int port);
};

}

#endif

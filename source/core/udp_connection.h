#ifndef UDP_CONNECTION_H
#define UDP_CONNECTION_H

#include <string>
#include <boost/asio.hpp>

#include "connection.h"
#include "types_ecs.h"

namespace ecs
{

class UdpConnection : public Connection
{
public:
    UdpConnection() :
        socket_(io_service_), is_connected_(false) {};
    virtual ~UdpConnection() {};

    virtual ByteArray ReceiveData();
    virtual void SendData(const ByteArray& data);
    virtual void Configure(const ProgramOptions& options);

private:
    boost::asio::io_service io_service_;
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint remote_point_;
    boost::asio::ip::udp::endpoint local_point_;

    bool is_connected_;

    void Connect();
    void SetLocalPoint(std::string address, int port);
    void SetRemotePoint(std::string address, int port);
};

}

#endif

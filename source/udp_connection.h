#ifndef UDP_CONNECTION_H
#define UDP_CONNECTION_H

#include <string>
#include <boost/asio.hpp>

namespace virt_dashboard
{

class UdpConnection
{
public:
    UdpConnection() :
        socket_(io_service_), is_connected_(false) {};

    void SetLocalPoint(std::string address, int port);
    void SetRemotePoint(std::string address, int port);

    void GetData();

private:
    static const int kInBufferLength;

    boost::asio::io_service io_service_;
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint remote_point_;
    boost::asio::ip::udp::endpoint local_point_;

    bool is_connected_;

    void SendRequest(std::string request);
    std::string ReceiveAnswer();
    void Connect();
};

}

#endif

#include "udp_connection.h"

#include <iostream>

#include <boost/bind.hpp>

using namespace std;
using namespace virt_dashboard;

const int UdpConnection::kInBufferLength = 165536;

void UdpConnection::Connect()
{
    if ( ! is_connected_ )
    {
        try
        {
            if ( socket_.is_open() )
                socket_.close();

            boost::system::error_code error;

            socket_.open(boost::asio::ip::udp::v4());

            socket_.bind(local_point_, error);

            if ( error == 0 )
                is_connected_ = true;
        }
        catch (exception& ex)
        {
            cout << "UdpConnection - error = " << ex.what() << endl;
        }
    }
}

void UdpConnection::GetData()
{
    string answer = ReceiveAnswer();
}

string UdpConnection::ReceiveAnswer()
{
    Connect();

    if ( ! is_connected_ )
        return string();

    char buffer[kInBufferLength];

    try
    {
        if ( socket_.available() != 0 )
            socket_.receive_from(boost::asio::buffer(buffer, kInBufferLength), remote_point_);
    }
    catch ( boost::system::system_error error )
    {
        is_connected_ = false;
        return string();
    }

    //cout << "UdpConnection::ReceiveAnswer() - buffer = " << buffer << endl;

    return string(buffer);
}

void UdpConnection::SetLocalPoint(string address, int port)
{
    boost::asio::ip::address ip_address = boost::asio::ip::address::from_string(address);
    local_point_ = boost::asio::ip::udp::endpoint(ip_address, port);
}

void UdpConnection::SetRemotePoint(string address, int port)
{
    boost::asio::ip::address ip_address = boost::asio::ip::address::from_string(address);
    remote_point_ = boost::asio::ip::udp::endpoint(ip_address, port);
}

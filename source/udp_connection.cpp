#include "udp_connection.h"

#include <iostream>

#include <boost/bind.hpp>

using namespace std;
using namespace virt_dashboard;

const int UdpConnection::kInBufferLength = 1024;

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

ByteArray UdpConnection::ReceiveData()
{
    Connect();

    if ( ! is_connected_ )
        return ByteArray();

    ByteArray result;
    result.reserve(kInBufferLength);

    try
    {
        if ( socket_.available() != 0 )
            socket_.receive_from(boost::asio::buffer(result, kInBufferLength), remote_point_);
    }
    catch ( boost::system::system_error error )
    {
        is_connected_ = false;
        return ByteArray();
    }

    //cout << "UdpConnection::ReceiveAnswer() - buffer = " << buffer << endl;

    return result;
}

void UdpConnection::SendData(ByteArray data)
{
    /* FIXME: Implement this method */
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

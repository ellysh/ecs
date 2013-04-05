#include "udp_connection_impl.h"

#include <iostream>
#include <boost/bind.hpp>

using namespace std;
using namespace ecs;

namespace ip = boost::asio::ip;

UdpConnectionImpl::UdpConnectionImpl(const string address_local, const int port_local,
                                     const string address_remote, const int port_remote) : socket_(io_service_)
{
    Connect(address_local, port_local);

    remote_point_ = GetEndPoint(address_remote, port_remote);
}

void UdpConnectionImpl::Connect(const string address, const int port)
{
    try
    {
        if ( socket_.is_open() )
            socket_.close();

        boost::system::error_code error;

        socket_.open(ip::udp::v4());

        socket_.bind(GetEndPoint(address, port), error);

        if ( error != 0 )
        {
            cout << "UdpConnectionImpl::Connect() - error = " << error << endl;
            exit(1);
        }
    }
    catch (exception& ex)
    {
        cout << "UdpConnectionImpl::Connect() - error = " << ex.what() << endl;
        exit(1);
    }
}

static ByteArray ArrayToVector(const char* array, const int size)
{
    if ( size > kMaxBufferSize )
        return ByteArray();

    ByteArray result;

    for ( int i = 0; i < size; i++ )
        result.push_back(array[i]);

    return result;
}

ByteArray UdpConnectionImpl::ReceiveData()
{
    char buffer[kMaxBufferSize];
    size_t bytes_transferred;

    try
    {
        /* FIXME: Try to use receive() method instead the receive_from() one */
        if ( socket_.available() != 0 )
            bytes_transferred = socket_.receive_from(
                                    boost::asio::buffer(buffer, kMaxBufferSize),
                                    remote_point_);
    }
    catch ( boost::system::system_error error )
    {
        cout << "SerialConnection - error = " << error.what() << endl;
        exit(1);
    }

    return ArrayToVector(buffer, bytes_transferred);
}

void UdpConnectionImpl::SendData(const ByteArray& data)
{
    if ( data.empty() )
        return;

    try
    {
        socket_.send_to(boost::asio::buffer(data), remote_point_);
    }
    catch ( boost::system::system_error error )
    {
        cout << "UdpConnection::SendData() - error = " << error.what() << " code = " << error.code() << endl;
        exit(1);
    }
}

ip::udp::endpoint UdpConnectionImpl::GetEndPoint(const string address, const int port)
{
    ip::address ip_address = ip::address::from_string(address);
    return ip::udp::endpoint(ip_address, port);
}
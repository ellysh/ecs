#include "serial_connection.h"

#include "program_options.h"

using namespace std;
using namespace virt_dashboard;

SerialConnection::~SerialConnection()
{
    if ( connection_ != NULL )
        delete connection_;
}

ByteArray SerialConnection::ReceiveData()
{
    if ( ! IsConnected() )
        return ByteArray();

    return connection_->ReceiveAnswer(kInBufferLength);
}

void SerialConnection::SendData(const ByteArray& data)
{
    if ( ! IsConnected() )
        return;

    connection_->SendRequest(data);
}

void SerialConnection::Configure(const ProgramOptions& options)
{
    if ( IsConnected() )
        return;

    string dev_file = options.GetString(kDevFile);
    int baud_rate = options.GetInt(kBaudRate);

    connection_ = new serial::SerialConnection(dev_file, baud_rate);
}

bool SerialConnection::IsConnected() const
{
    if ( connection_ != NULL )
        return true;
    else
        return false;
}

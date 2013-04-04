#include "serial_connection.h"

#include "program_options.h"
#include "option_names.h"
#include "thread.h"

using namespace std;
using namespace ecs;

static ByteArray gReceiveData;

SerialConnection::~SerialConnection()
{
    if ( connection_ != NULL )
        delete connection_;
}

void* ReceiveDataLoop(void* args)
{
    serial::SerialConnection* connection = reinterpret_cast<serial::SerialConnection*>(args);

    gReceiveData = connection->ReceiveData(kMaxBufferSize);
}

ByteArray SerialConnection::ReceiveData()
{
    if ( ! IsConnected() )
        return ByteArray();

    pthread_t thread = CreateThread(ReceiveDataLoop, reinterpret_cast<void*>(connection_));

    int error =  CancelThread(thread, timeout_);

    if ( error != 0 )
    {
        cout << "receive - TIMEOUT" << endl;
        return ByteArray();
    }

    return gReceiveData;
}

void SerialConnection::SendData(const ByteArray& data)
{
    if ( ! IsConnected() )
        return;

    connection_->SendData(data);
}

void SerialConnection::Configure(const ProgramOptions& options)
{
    if ( IsConnected() )
        return;

    string dev_file = options.GetString(kDevFile);
    int baud_rate = options.GetInt(kBaudRate);

    connection_ = new serial::SerialConnection(dev_file, baud_rate);

    timeout_ = options.GetInt(kTimeout);
}

bool SerialConnection::IsConnected() const
{
    if ( connection_ != NULL )
        return true;
    else
        return false;
}

#include "udp_connection.h"

#include "program_options.h"
#include "option_names.h"
#include "thread.h"
#include "functions.h"

using namespace std;
using namespace ecs;

static ByteArray gReceiveData;
static bool gIsReceived = false;

UdpConnection::~UdpConnection()
{
    if (  IsInit() )
        delete connection_;
}

static void* ReceiveDataLoop(void* args)
{
    /* FIXME: This method is the same as SerialConnection one */
    UdpConnectionImpl* connection = reinterpret_cast<UdpConnectionImpl*>(args);

    gReceiveData = connection->ReceiveData(kMaxBufferSize);

    gIsReceived = true;
}

ByteArray UdpConnection::ReceiveData()
{
    /* FIXME: This method is the same as SerialConnection one */
    if ( ! IsInit() )
        return ByteArray();

    pthread_t thread = CreateThread(ReceiveDataLoop, reinterpret_cast<void*>(connection_));

    int error;
    if ( gIsReceived )
        error =  CancelThread(thread, timeout_);
    else
        error = CancelThread(thread, 0);

    if ( error != 0 )
    {
        if ( error == ETIMEDOUT )
            cout << GetTimeStamp() << "\treceive - TIMEOUT" << endl;

        return ByteArray();
    }

    return gReceiveData;
}

void UdpConnection::SendData(const ByteArray& data)
{
    if ( ! IsInit() )
        return;

    connection_->SendData(data);
}

void UdpConnection::Configure(const ProgramOptions& options)
{
    if ( IsInit() )
        return;

    string address_local = options.GetString(kIpLocal);
    int port_local = options.GetInt(kPortLocal);

    string address_remote = options.GetString(kIpRemote);
    int port_remote = options.GetInt(kPortRemote);

    connection_ = new UdpConnectionImpl(address_local, port_local,
                                        address_remote, port_remote);

    timeout_ = options.GetInt(kTimeout);
}

bool UdpConnection::IsInit() const
{
    if ( connection_ != NULL )
        return true;
    else
        return false;
}

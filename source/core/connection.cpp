#include "connection.h"

#include <iostream>

#include "connection_impl.h"
#include "thread.h"
#include "functions.h"

using namespace std;
using namespace ecs;

static ByteArray gReceiveData;
static bool gIsReceived = false;

Connection::~Connection()
{
    delete connection_;
}

static void* ReceiveDataLoop(void* args)
{
    ConnectionImpl* connection = reinterpret_cast<ConnectionImpl*>(args);

    gReceiveData = connection->ReceiveData(kMaxBufferSize);

    gIsReceived = true;
}

ByteArray Connection::ReceiveData()
{
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

void Connection::SendData(const ByteArray& data)
{
    connection_->SendData(data);
}

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
    /* FIXME: Implement this method */
    return ByteArray();
}

void SerialConnection::SendData(const ByteArray& data)
{
    /* FIXME: Implement this method */
}

void SerialConnection::Configure(const ProgramOptions& options)
{
    /* FIXME: Implement this method */
}


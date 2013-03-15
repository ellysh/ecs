#ifndef VD_SERIAL_CONNECTION_H
#define VD_SERIAL_CONNECTION_H

#include "connection.h"
#include "types_vdb.h"

#include <libserial/serial_connection.h>

namespace virt_dashboard
{

class SerialConnection : public Connection
{
public:
    SerialConnection() : connection_(NULL) {};
    virtual ~SerialConnection();

    virtual ByteArray ReceiveData();
    virtual void SendData(const ByteArray& data);
    virtual void Configure(const ProgramOptions& options);

private:
    serial::SerialConnection* connection_;
};

}

#endif

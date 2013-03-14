#ifndef SERIAL_CONNECTION_H
#define SERIAL_CONNECTION_H

#include "connection.h"
#include "types_vdb.h"

namespace virt_dashboard
{

class SerialConnection : public Connection
{
public:
    SerialConnection() {};
    virtual ~SerialConnection() {};

    virtual ByteArray ReceiveData();
    virtual void SendData(const ByteArray& data);
    virtual void Configure(const ProgramOptions& options);

private:
};

}

#endif

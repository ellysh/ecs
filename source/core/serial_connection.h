#ifndef VD_SERIAL_CONNECTION_H
#define VD_SERIAL_CONNECTION_H

#include "connection.h"

namespace ecs
{

class SerialConnection : public Connection
{
public:
    virtual ~SerialConnection() {};

    virtual void Configure(const ProgramOptions& options);
};

}

#endif

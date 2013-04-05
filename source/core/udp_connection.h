#ifndef UDP_CONNECTION_H
#define UDP_CONNECTION_H

#include "connection.h"

namespace ecs
{

class UdpConnection : public Connection
{
public:
    virtual ~UdpConnection() {};

    virtual void Configure(const ProgramOptions& options);
};

}

#endif

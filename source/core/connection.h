#ifndef CONNECTION_H
#define CONNECTION_H

#include <cstdlib>

#include "types_ecs.h"

namespace ecs
{

static const int kMaxBufferSize = 1024;

class ProgramOptions;
class ConnectionImpl;

class Connection
{
public:
    Connection(ConnectionImpl* const connection) : connection_(connection) {};
    virtual ~Connection();

    ByteArray ReceiveData();
    void SendData(const ByteArray& data);

protected:
    ConnectionImpl* connection_;
    long timeout_;

    DISALLOW_COPY_AND_ASSIGN(Connection)
};

}

#endif

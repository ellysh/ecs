#ifndef CONNECTION_H
#define CONNECTION_H

#include "types_ecs.h"

namespace ecs
{

static const int kMaxBufferSize = 1024;

class ProgramOptions;
class ConnectionImpl;

class Connection
{
public:
    Connection() {};
    virtual ~Connection() {};

    virtual ByteArray ReceiveData() = 0;
    virtual void SendData(const ByteArray& data) = 0;
    virtual void Configure(const ProgramOptions& options) = 0;

protected:
    ConnectionImpl* connection_;
    long timeout_;

    bool IsInit() const;

    DISALLOW_COPY_AND_ASSIGN(Connection)
};

}

#endif

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
    Connection() : connection_(NULL) {};
    virtual ~Connection();

    ByteArray ReceiveData();
    void SendData(const ByteArray& data);
    virtual void Configure(const ProgramOptions& options) = 0;

protected:
    ConnectionImpl* connection_;
    long timeout_;

    bool IsInit() const;

    DISALLOW_COPY_AND_ASSIGN(Connection)
};

}

#endif

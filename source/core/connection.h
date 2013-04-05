#ifndef CONNECTION_H
#define CONNECTION_H

#include "types_ecs.h"

namespace ecs
{

class ProgramOptions;

class Connection
{
public:
    Connection() {};
    virtual ~Connection() {};

    virtual ByteArray ReceiveData() = 0;
    virtual void SendData(const ByteArray& data) = 0;
    virtual void Configure(const ProgramOptions& options) = 0;
};

}

#endif

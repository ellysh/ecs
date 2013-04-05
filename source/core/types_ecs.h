#ifndef TYPES_ECS_H
#define TYPES_ECS_H

#include <vector>

namespace ecs
{

/* A macro to disallow the copy constructor and operator= functions.
 * This should be used in the private: declarations for a class. */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
private: \
    TypeName(const TypeName&);               \
    TypeName& operator=(const TypeName&);

typedef unsigned char Byte;
typedef std::vector<Byte> ByteArray;

static const int kMaxBufferSize = 1024;

}

#endif

#ifndef FUNCTIONS_VDB_H
#define FUNCTIONS_VDB_H

#include "types_vdb.h"

namespace virt_dashboard
{

void PrintByteArray(ByteArray input)
{
    std::cout << "[ ";
    for ( int i = 0; i < input.size(); i++ )
        std::cout << std::hex << (int)input[i] << " ";
    std::cout << "]" << std::endl;
}

}

#endif

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types_ecs.h"

#include <string>

namespace ecs
{

void PrintByteArray(const ByteArray input);
Byte StringToByte(const std::string input);
ByteArray StringToArray(const std::string input, const size_t start, const size_t end);

}

#endif

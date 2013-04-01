#include "functions.h"

#include <iostream>
#include <sstream>

using namespace std;
using namespace ecs;

void ecs::PrintByteArray(const ByteArray input)
{
    cout << "[ ";
    for ( int i = 0; i < input.size(); i++ )
        cout << hex << (int)input[i] << " ";
    cout << "]" << endl;
}

Byte ecs::StringToByte(const string input)
{
    int result;
    stringstream stream;
    stream << hex << input;
    stream >> result;

    return result;
}

ByteArray ecs::StringToArray(const string input, const size_t start, const size_t end)
{
    if ( input.size() < end )
        return ByteArray();

    ByteArray result;
    string byte;

    for ( size_t i = start; i < end; i+=3 )
    {
        byte.append(1, input[i]);
        byte.append(1, input[i+1]);

        result.push_back(StringToByte(byte));

        byte.clear();
    }

    return result;
}

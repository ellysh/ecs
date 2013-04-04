#include "functions.h"

#include <iostream>
#include <sstream>

#include <sys/time.h>

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

string ecs::GetTimeStamp()
{
    char tmbuf[128], tmbuf2[128];
    struct timeval time;
    struct tm* tm;

    gettimeofday(&time, 0);
    tm = localtime(&(time.tv_sec));

    strftime(tmbuf2, sizeof(tmbuf2),"%d/%m/%y %H:%M:%S", tm);
    sprintf( tmbuf, "[%s.%03d] ", tmbuf2, (int)(time.tv_usec/1000) );

    return tmbuf;
}

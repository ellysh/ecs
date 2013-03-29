#include "functions_vdb.h"

#include <iostream>

using namespace std;
using namespace virt_dashboard;

void PrintByteArray(ByteArray input)
{
    cout << "[ ";
    for ( int i = 0; i < input.size(); i++ )
        cout << hex << (int)input[i] << " ";
    cout << "]" << endl;
}

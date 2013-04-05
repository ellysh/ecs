#include "serial_connection.h"

#include <libserial/serial_connection.h>

#include "connection_impl.h"
#include "program_options.h"
#include "option_names.h"

using namespace std;
using namespace ecs;

void SerialConnection::Configure(const ProgramOptions& options)
{
    if ( IsInit() )
        return;

    string dev_file = options.GetString(kDevFile);
    int baud_rate = options.GetInt(kBaudRate);

    serial::SerialConnection* serial_connection = new serial::SerialConnection(dev_file, baud_rate);
    connection_ = new ConnectionImpl(serial_connection);

    timeout_ = options.GetInt(kTimeout);
}

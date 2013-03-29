#include "virtual_uso.h"

#include <iostream>

#include "program_options.h"
#include "uso_parser.h"
#include "protocol_uso.h"
#include "functions_vdb.h"

using namespace std;
using namespace virt_dashboard;

void VirtualUso::CreateProtocol()
{
    UsoParser parser(options_.GetString(kScenario));

    protocol_ = new ProtocolUso(parser.GetRequests());
}

VirtualUso::~VirtualUso()
{
    delete protocol_;
}

void VirtualUso::Start()
{
    ByteArray request;

    while( true )
    {
        request = protocol_->GetRequest();

        if ( request.empty() )
            continue;

        cout << "main()" << endl;
        cout << "\trequest = ";
        PrintByteArray(request);

        connection_->SendData(request);

        cout << "\tdelay = " << dec << protocol_->GetDelay() << endl;
        usleep(protocol_->GetDelay() * 1000);

        protocol_->NextRequest();
    }
}

#include "protocol_host.h"

#include "scenario_conclusion.h"

using namespace std;
using namespace virt_dashboard;

ByteArray ProtocolHost::GetRequest()
{
    if ( requests_.empty() )
        ScenarioConclusion::ExitSuccess();

    return requests_.front().first;
}

int ProtocolHost::GetDelay()
{
    return requests_.front().second;
}

void ProtocolHost::NextRequest()
{
    requests_.pop_front();
}

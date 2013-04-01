#include "protocol_host.h"

#include "scenario_conclusion.h"

using namespace std;
using namespace ecs;

ByteArray ProtocolHost::GetRequest() const
{
    if ( requests_.empty() )
        ScenarioConclusion::ExitSuccess();

    return requests_.front().first;
}

int ProtocolHost::GetDelay() const
{
    return requests_.front().second;
}

void ProtocolHost::NextRequest()
{
    requests_.pop_front();
}

#include "protocol_uso.h"

#include "scenario_conclusion.h"

using namespace std;
using namespace virt_dashboard;

ByteArray ProtocolUso::GetRequest()
{
    if ( requests_.empty() )
        ScenarioConclusion::ExitSuccess();

    return requests_.front().first;
}

int ProtocolUso::GetDelay()
{
    return requests_.front().second;
}

void ProtocolUso::NextRequest()
{
    requests_.pop_front();
}

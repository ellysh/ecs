#ifndef SCENARIO_CONCLUSION_H
#define SCENARIO_CONCLUSION_H

namespace ecs
{

class ScenarioConclusion
{
public:
    static void ExitSuccess();
    static void ExitFail();
    static void Exit();
};

}

#endif

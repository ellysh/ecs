#ifndef VIRTUAL_CONTROLLER_H
#define VIRTUAL_CONTROLLER_H

namespace virt_dashboard
{

class ProgramOptions;

class VirtualController
{
public:
    VirtualController(ProgramOptions& options) : options_(options) {};
    void Start();

private:
    ProgramOptions& options_;
};

}

#endif

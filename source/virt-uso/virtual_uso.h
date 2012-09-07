#ifndef VIRTUAL_USO_H
#define VIRTUAL_USO_H

namespace virt_dashboard
{

class ProgramOptions;

class VirtualUso
{
public:
    VirtualUso(ProgramOptions& options) : options_(options) {};
    void Start();

private:
    ProgramOptions& options_;
};

}

#endif

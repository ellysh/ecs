#ifndef USO_PARSER_H
#define USO_PARSER_H

#include <string>
#include <list>

#include "types_vdb.h"

namespace virt_dashboard
{

class UsoParser
{
private:
    typedef std::list< std::pair<ByteArray, int> > RequestMap;

public:
    UsoParser(std::string filename);
    virtual ~UsoParser() {}

    ByteArray GetRequest();
    int GetDelay();
    void NextRequest();

private:
    RequestMap requests_;

    void ParseFile(std::string& filename);
};

}

#endif

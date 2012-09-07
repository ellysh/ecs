#ifndef CONTROLLER_PARSER_H
#define CONTROLLER_PARSER_H

#include <string>
#include <list>

#include "types_vdb.h"

namespace virt_dashboard
{

class ControllerParser
{
private:
    typedef std::list< std::pair<ByteArray, ByteArray> > AnswerMap;

public:
    ControllerParser(std::string filename);

    ByteArray GetAnswer(ByteArray request);

private:
    AnswerMap answers_;

    void ParseFile(std::string& filename);
};

}

#endif

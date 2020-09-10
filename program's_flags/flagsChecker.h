#pragma once

#include <map>
#include <string>

class EFlags
{
    int flagSumm_ = 0;
    bool Good = true;

    void DumpHelp();
public:
    bool construct(int argc, char const * const argv[]);
    bool operator[](std::string const & flag) const;
};

extern EFlags flags;
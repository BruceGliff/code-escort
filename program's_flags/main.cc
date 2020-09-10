#include "flagsChecker.h"
#include "errorDumper.h"


EFlags flags;
int main(int argc, char * argv[])
{
    if (!flags.construct(argc, argv))
    {
        errorDumper::ErrorDump("bad flags");
        return -1;
    }

    if (flags["-d"])
    {
        errorDumper::SilenceDump("flag -d");
    }
    if (flags["-a"])
    {
        errorDumper::SilenceDump("flag -a");
    }

    return 0;
}
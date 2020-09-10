#include "errors_dumper/errorDumper.h"
#include "flags_checker/flagsChecker.h"



EFlags flags;

int main(int argc, char * argv[])
{
    if (!flags.construct(argc, argv))
    {
        errorDumper::ErrorDump("This is the error");
        return -1;
    }

    if (flags["-a"])
        errorDumper::SilenceDump("-a");

    if (flags["-d"])
        errorDumper::SilenceDump("-d");

}
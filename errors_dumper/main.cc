#include "errorDumper.h"

int main()
{
    errorDumper::SilenceDump("Whis is silenceDump");
    errorDumper::ErrorDump("Whis is errorDump");

    return 0;
}
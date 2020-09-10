#include <iostream>
#include "errorDumper.h"

void errorDumper::SilenceDump(char const* string)
{
	std::cout << "{Silence dump} " << string << std::endl;
}

void errorDumper::ErrorDump(char const* string)
{
	std::cerr << "{Error} " << string << std::endl;
}

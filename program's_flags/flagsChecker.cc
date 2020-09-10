#include "FlagsChecker.h"
#include "errorDumper.h"
#include <string>
#include <iostream>


class KeyWords
{
    std::map<std::string, std::pair<int, std::string>> Word; // < key, <value, disctoption> >

public:
    KeyWords();
    int operator[](std::string const & word) const;
    std::string const & help(std::string const &) const;

    typedef std::map<std::string, std::pair<int, std::string>>::const_iterator const_iterator;

    const_iterator begin() const { return Word.begin(); }
    const_iterator end()   const { return Word.end();   }
};

KeyWords::KeyWords()
{
    Word["-h"] = std::pair<int, std::string>{0b1,       "Dump flags discription"};                                  // help
    Word["-d"] = std::pair<int, std::string>{0b1,       "flag example"};                                            // flag example
    Word["-a"] = std::pair<int, std::string>{0b1,       "flag example"};                                            // flag example
}

namespace Dictionary
{
    static KeyWords Word{};
};

int ParseParam(char const * arg);

int KeyWords::operator[](std::string const & word) const
{
    auto const Iter = Word.find(word);
    if (Iter != Word.end())
        return Iter->second.first;
    else
        return -1;
}



bool EFlags::construct(int argc, char const * const argv[])
{
    while (--argc > 0)
    {
        int const res = Dictionary::Word[argv[argc]];
        if (res == Dictionary::Word["-h"])
        {
            DumpHelp();
            return false;
        }
        if (res == -1)
        {
            errorDumper::ErrorDump("Wrong params. -h for help /   FlagsChecker.cc for help :)   \\");
            Good = false;
            return Good;
        }

        flagSumm_ |= res;
    }

    return Good;
}

bool EFlags::operator[](std::string const & flag) const
{
    return flagSumm_ & Dictionary::Word[flag];
}

void EFlags::DumpHelp()
{
    std::cout << "_________________" << std::endl;
    std::cout << "      HELP       " << std::endl;

    for (auto && x : Dictionary::Word)
        std::cout << x.first << " - " << x.second.second << std::endl;

    std::cout << "-----------------" << std::endl;
}

int ParseParam(char const * arg)
{
    if (arg[0] != '-')
        return -1;

    return Dictionary::Word[arg];
}
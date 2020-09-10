#include "FlagsChecker.h"
#include "errorDumper.h"
#include <string>
#include <iostream>
#include <vector>


class KeyWords
{
    std::map<std::string, std::pair<int, std::string>> wordMap_; // < key_it, <value, disctoption_it> >
    std::map<std::string, std::string> dictionary_;

    void GetDictionary();
    void GenerateKeys();

public:
    KeyWords();
    int operator[](std::string const & word) const;
    std::string const & help(std::string const &) const;

    typedef std::map<std::string, std::pair<int, std::string>>::const_iterator const_iterator;

    const_iterator begin() const { return wordMap_.begin(); }
    const_iterator end()   const { return wordMap_.end();   }
};

void KeyWords::GetDictionary()
{
    // TODO make read from file
    dictionary_["-h"] = "Dump flags discription";                                  // help
    dictionary_["-d"] = "flag example";                                            // flag example
    dictionary_["-a"] = "flag example";                                            // flag example
}

void KeyWords::GenerateKeys()
{
    int y = 1;
    for (auto && x : dictionary_)
    {
        wordMap_[x.first] = std::pair<int, std::string const &>{y, x.second};
        y = y << 1;
    }
}
KeyWords::KeyWords()
{
    GetDictionary();
    GenerateKeys();
}

namespace Dictionary
{
    static KeyWords Word{};
};

int ParseParam(char const * arg);

int KeyWords::operator[](std::string const & word) const
{
    auto const Iter = wordMap_.find(word);
    if (Iter != wordMap_.end())
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
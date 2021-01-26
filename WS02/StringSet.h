#ifndef WS02_STRING_SET_H
#define WS02_STRING_SET_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

namespace sdds {
    class StringSet {
        char *fileName;
        size_t wordNo;

        struct Word {
            size_t index;
            std::string value;
            Word *nextWord;
        };
        Word *start;
        Word *stop;

    public:
        StringSet();

        StringSet(const char *fileName);

        StringSet(const StringSet &source);

        StringSet &operator=(const StringSet &source);

        StringSet(StringSet &&source);

        StringSet &operator=(StringSet &&source);

        ~StringSet();

        size_t size() const;

        std::string operator[](size_t index) const;

    private:
        void push(const std::string &value);
        void readFromFile();
        void releaseMemory();
        void setDefaultState();
    };
}

#endif
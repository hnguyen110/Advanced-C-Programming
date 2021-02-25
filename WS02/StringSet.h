/*
 * Purpose: Workshop 2
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Sunday Jan/28/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

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
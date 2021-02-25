/*
 * Purpose: Workshop 5
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS05_SPELLCHECKER_H
#define WS05_SPELLCHECKER_H

#include <iostream>
#include <string>
#include <fstream>
#include "Utils.h"

namespace sdds {
    class SpellChecker {
        std::string _badWords[6];
        std::string _goodWords[6];
        size_t _correctionCounter[6];

    public:
        SpellChecker(const char *filename);

        void operator()(std::string &text);

        void showStatistics(std::ostream &out) const;
    };
}


#endif

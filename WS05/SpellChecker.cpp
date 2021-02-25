/*
 * Purpose: Workshop 5
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "SpellChecker.h"

namespace sdds {
    SpellChecker::SpellChecker(const char *filename) {
        if (filename != nullptr) {
            std::fstream file(filename);
            if (file.is_open()) {
                char buffer[256];
                size_t index = 0;
                while (file.good()) {
                    size_t position = 0;
                    file.getline(buffer, 255, '\n');
                    if (buffer[0] != '\0') {
                        _badWords[index] = Utils::extract(buffer, ' ', position);
                        _goodWords[index] = Utils::extract(buffer, '\n', position);
                        _correctionCounter[index] = 0;
                        ++index;
                    }
                }
                file.close();
            } else
                throw std::string("Bad file name!");
        } else
            throw std::string("Missing file name!");
    }

    void SpellChecker::operator()(std::string &text) {
        for (size_t index = 0; index < 6; ++index) {
            size_t next = std::string::npos;
            while ((next = text.find(_badWords[index])) != std::string::npos) {
                text.replace(next, _badWords[index].length(), _goodWords[index]);
                _correctionCounter[index]++;
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream &out) const {
        out << "Spellchecker Statistics" << std::endl;
        for (size_t index = 0; index < 6; ++index) {
            out.width(15);
            out << std::right << _badWords[index]
                << ":"
                << " "
                << _correctionCounter[index]
                << " "
                << "replacements"
                << std::endl;
        }
    }
}
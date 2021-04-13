// Name: Hien Dao The Nguyen
// Seneca Student ID: 103 152 195
// Seneca email: hnguyen110@myseneca.ca
// Date of completion: Friday, March 26, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace sdds {
    Utilities::Utilities() { _width = 1; }

    void Utilities::setFieldWidth(size_t width) {
        _width = width;
    }

    size_t Utilities::getFieldWidth() const {
        return _width;
    }

    std::string Utilities::extractToken(const std::string &string, size_t &position, bool &more) {
        std::string token;
        if (more && string.length()) {
            size_t previous_position = position;
            size_t start = position;
            if (start != 0) start++;
            for (size_t index = start; index < string.size(); ++index) {
                if (string[index] != getDelimiter()) {
                    token += string[index];
                } else {
                    position = index;
                    break;
                }
            }
            if (position == previous_position) more = false;
        }
        if (token.empty()) {
            position = 0;
            more = false;
            setFieldWidth(1);
            throw std::string("No Token");
        }
        if (_width < token.length()) setFieldWidth(token.length());
        return token;
    }

    void Utilities::setDelimiter(char delimiter) {
        _delimiter = delimiter;
    }

    char Utilities::getDelimiter() {
        return _delimiter;
    }
}
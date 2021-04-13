// Name: Hien Dao The Nguyen
// Seneca Student ID: 103 152 195
// Seneca email: hnguyen110@myseneca.ca
// Date of completion: Thursday, April 8, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef MS1_UTILITIES_H
#define MS1_UTILITIES_H

#include <iostream>
#include <string>

namespace sdds {
    class Utilities {
    private:
        size_t _width;
        static char _delimiter;

    public:
        Utilities();

        void setFieldWidth(size_t width);

        [[nodiscard]] size_t getFieldWidth() const;

        std::string extractToken(const std::string &string, size_t &position, bool &more);

        static void setDelimiter(char delimiter);

        static char getDelimiter();
    };

    inline char Utilities::_delimiter = ',';
}

#endif
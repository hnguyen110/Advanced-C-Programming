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

        size_t getFieldWidth() const;

        std::string extractToken(const std::string &string, size_t &position, bool &more);

        static void setDelimiter(char delimiter);

        static char getDelimiter();
    };

    inline char Utilities::_delimiter = ',';
}

#endif
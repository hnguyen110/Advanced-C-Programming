#ifndef WS06_UTILITIES_H
#define WS06_UTILITIES_H

#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
    std::string trim(const std::string &string);

    std::string extract(std::istream &is, const char &delimiter = ',');

    bool isEmptyOrWhiteSpace(const std::string& string);

    bool isNumber(const std::string& string);

    Vehicle *createInstance(std::istream &istream);
}

#endif
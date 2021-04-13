/*
 * Purpose: Workshop 6
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Mar/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

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
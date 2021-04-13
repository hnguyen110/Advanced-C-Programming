/*
 * Purpose: Workshop 6
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Mar/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Racecar.h"
#include "Utilities.h"

namespace sdds {
    Racecar::Racecar(std::istream &istream) : Car(istream) {
        _booster = std::stod(extract(istream));
    }

    void Racecar::display(std::ostream &out) const {
        Car::display(out);
        out << "*";
    }

    double Racecar::topSpeed() const {
        return Car::topSpeed() * (1 + _booster);
    }
}
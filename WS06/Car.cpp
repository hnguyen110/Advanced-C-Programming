/*
 * Purpose: Workshop 6
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Mar/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Car.h"
#include "Utilities.h"

namespace sdds {
    Car::Car(std::istream &istream) {
        _maker = extract(istream);

        auto condition = extract(istream);
        if (isEmptyOrWhiteSpace(condition))
            _condition = 'n';
        else if (condition == "n" || condition == "u" || condition == "b")
            _condition = condition;
        else {
            istream.clear();
            istream.ignore(2000, '\n');
            throw std::string("Invalid record!");
        }

        auto speed = extract(istream);
        if (isNumber(speed))
            _speed = std::stod(speed);
        else {
            istream.clear();
            istream.ignore(2000, '\n');
            throw std::string("Invalid record!");
        }
    }

    std::string Car::condition() const {
        return _condition;
    }

    double Car::topSpeed() const {
        return _speed;
    }

    void Car::display(std::ostream &out) const {
        out << "| ";
        out.width(10);
        out << std::right << _maker << " | ";
        out.width(6);
        if (condition() == "n")
            out << std::left << "new" << " | ";
        else if (condition() == "u")
            out << std::left << "used" << " | ";
        else if (condition() == "b")
            out << std::left << "broken" << " | ";
        out.width(6);
        out.setf(std::ios::fixed);
        out.precision(2);
        out << topSpeed() << " |";
        out.unsetf(std::ios::fixed);
    }

    void Car::setToEmptyState() {
        _maker = "";
        _condition = '\0';
        _speed = 0;
    }
}
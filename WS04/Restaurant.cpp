/*
 * Purpose: Workshop 4
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Monday Feb/08/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Restaurant.h"

namespace sdds {
    Restaurant::Restaurant() {
        setEmpty();
    }

    Restaurant::Restaurant(const Reservation *reservations[], size_t size) {
        _reservations = new Reservation *[size];
        for (auto index = 0u; index < size; ++index)
            _reservations[index] = new Reservation(*reservations[index]);
        _size = size;
    }

    Restaurant::Restaurant(const Restaurant &src) {
        setEmpty();
        *this = src;
    }

    Restaurant &Restaurant::operator=(const Restaurant &src) {
        if (this != &src) {
            if (_reservations != nullptr) clear();
            _reservations = new Reservation *[src._size];
            for (auto index = 0u; index < src._size; ++index)
                _reservations[index] = new Reservation(*src._reservations[index]);
            _size = src._size;
        }
        return *this;
    }

    Restaurant::Restaurant(Restaurant &&src) {
        setEmpty();
        *this = std::move(src);
    }

    Restaurant &Restaurant::operator=(Restaurant &&src) {
        if (this != &src) {
            if (_reservations != nullptr) clear();
            _reservations = src._reservations;
            src._reservations = nullptr;
            _size = src._size;
            src._size = 0;
        }
        return *this;
    }

    Restaurant::~Restaurant() {
        clear();
    }

    size_t Restaurant::size() const {
        return _size;
    }

    void Restaurant::setEmpty() {
        _reservations = nullptr;
        _size = 0;
    }

    void Restaurant::clear() {
        for (auto index = 0u; index < size(); ++index) {
            delete _reservations[index];
        }
        delete[] _reservations;
        _size = 0;
    }

    std::ostream &operator<<(std::ostream &os, const Restaurant &restaurant) {
        os << "--------------------------" << std::endl;
        os << "Fancy Restaurant " << "(" << ++restaurant.insertionCounter << ")" << std::endl;
        os << "--------------------------" << std::endl;
        if (!restaurant.size())
            os << "This restaurant is empty!" << std::endl;
        else
            for (auto index = 0u; index < restaurant.size(); ++index)
                os << *restaurant._reservations[index];
        os << "--------------------------" << std::endl;
        return os;
    }
}
/*
 * Purpose: Workshop 6
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Mar/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS06_RACE_CAR_H
#define WS06_RACE_CAR_H

#include "Car.h"

namespace sdds {
    class Racecar : public Car {
        double _booster;

    public:
        Racecar(std::istream &istream);

        void display(std::ostream &out) const;

        double topSpeed() const;
    };
}

#endif
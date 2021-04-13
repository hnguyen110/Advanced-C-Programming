/*
 * Purpose: Workshop 6
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Mar/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS06_CAR_H
#define WS06_CAR_H

#include <string>
#include <iostream>
#include "Vehicle.h"

namespace sdds {
    class Car : public Vehicle {
        std::string _maker;
        std::string _condition;
        double _speed;

    public:
        Car(std::istream &);

        std::string condition() const;

        double topSpeed() const;

        void display(std::ostream &out) const;

    private:
        void setToEmptyState();
    };
}


#endif

/*
 * Purpose: Workshop 6
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Mar/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>
#include <string>

namespace sdds {
    class Vehicle {
    public:
        virtual double topSpeed() const = 0;

        virtual void display(std::ostream &) const = 0;

        virtual std::string condition() const = 0;

        virtual ~Vehicle() {};
    };
}

#endif
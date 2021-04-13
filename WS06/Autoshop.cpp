/*
 * Purpose: Workshop 6
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Mar/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Autoshop.h"

namespace sdds {
    Autoshop &Autoshop::operator+=(Vehicle *vehicle) {
        _vehicles.push_back(vehicle);
        return *this;
    }

    void Autoshop::display(std::ostream &out) const {
        out << "--------------------------------" << std::endl;
        out << "| Cars in the autoshop!        |" << std::endl;
        out << "--------------------------------" << std::endl;
        for (auto iterator = _vehicles.begin(); iterator < _vehicles.end(); ++iterator) {
            (*iterator)->display(out);
            out << std::endl;
        }
        out << "--------------------------------" << std::endl;
    }

    Autoshop::~Autoshop() {
        for (auto& vehicle : _vehicles) {
            delete vehicle;
        }
    }
}
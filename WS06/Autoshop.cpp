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
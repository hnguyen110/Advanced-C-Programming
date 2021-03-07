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
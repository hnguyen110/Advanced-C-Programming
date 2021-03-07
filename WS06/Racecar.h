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
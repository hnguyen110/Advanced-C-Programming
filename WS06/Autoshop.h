#ifndef WS06_AUTO_SHOP_H
#define WS06_AUTO_SHOP_H

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
    class Autoshop {
        std::vector<Vehicle *> _vehicles;

    public:
        Autoshop &operator+=(Vehicle *vehicle);

        void display(std::ostream &out) const;

        template<typename GenericType>
        void select(GenericType test, std::list<const Vehicle*>& vehicles) {
            for (auto iterator = _vehicles.begin(); iterator < _vehicles.end(); ++iterator) {
                if (test(*iterator)) vehicles.push_back(*iterator);
            }
        }

        ~Autoshop();
    };
}

#endif

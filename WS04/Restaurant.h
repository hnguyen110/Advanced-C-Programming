/*
 * Purpose: Workshop 4
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Monday Feb/08/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS04_RESTAURANT_H
#define WS04_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace sdds {
    class Restaurant {
        Reservation **_reservations;
        size_t _size;
        static size_t insertionCounter;

    public:
        Restaurant();

        Restaurant(const Reservation *reservations[], size_t size);

        Restaurant(const Restaurant &src);

        Restaurant &operator=(const Restaurant &src);

        Restaurant(Restaurant &&src);

        Restaurant &operator=(Restaurant &&src);

        ~Restaurant();

        size_t size() const;

        void setEmpty();

        void clear();

        friend std::ostream &operator<<(std::ostream &os, const Restaurant &restaurant);
    };

    inline size_t Restaurant::insertionCounter = 0u;
}


#endif

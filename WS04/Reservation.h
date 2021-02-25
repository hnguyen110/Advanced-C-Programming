/*
 * Purpose: Workshop 4
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Monday Feb/08/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS04_RESERVATION_H
#define WS04_RESERVATION_H

#include <string>
#include <iostream>

namespace sdds {
    constexpr size_t MIN_DAY = 1u;
    constexpr size_t MIN_HOUR = 1u;

    class Reservation {
        std::string _id;
        std::string _name;
        std::string _email;
        size_t _peopleNo;
        size_t _day;
        size_t _hour;

    public:
        Reservation();

        Reservation(const std::string &reservation);

        Reservation(const Reservation &src);

        friend std::ostream &operator<<(std::ostream &os, const Reservation &reservation);

        void setEmpty();

    private:
        std::string trim(const std::string &string);

        std::string extract(const std::string &reservation, const char &delimiter, size_t &position);
    };
}


#endif

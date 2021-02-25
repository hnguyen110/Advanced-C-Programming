/*
 * Purpose: Workshop 4
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Monday Feb/08/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Reservation.h"

namespace sdds {
    Reservation::Reservation() {
        setEmpty();
    }

    Reservation::Reservation(const std::string &reservation) {
        size_t index = 0u;
        _id = extract(reservation, ':', index);
        _name = extract(reservation, ',', index);
        _email = extract(reservation, ',', index);
        _peopleNo = std::stoi(extract(reservation, ',', index));
        _day = std::stoi(extract(reservation, ',', index));
        _hour = std::stoi(extract(reservation, ',', index));
    }

    Reservation::Reservation(const Reservation &src) {
        if (this != &src) {
            _id = src._id;
            _name = src._name;
            _email = src._email;
            _peopleNo = src._peopleNo;
            _day = src._day;
            _hour = src._hour;
        } else setEmpty();
    }

    std::ostream &operator<<(std::ostream &os, const Reservation &reservation) {
        os << "Reservation ";
        os.width(10);
        os << std::right << reservation._id << ":";
        os.width(21);
        os << reservation._name << "  ";
        os.width(24);
        os << std::left << '<' + reservation._email + '>';
        if (reservation._hour >= 6 && reservation._hour <= 9)
            os << "Breakfast on day ";
        else if (reservation._hour >= 11 && reservation._hour <= 15)
            os << "Lunch on day ";
        else if (reservation._hour >= 17 && reservation._hour <= 21)
            os << "Dinner on day ";
        else os << "Drinks on day ";
        os << reservation._day << " @ ";
        os << reservation._hour << ":00";
        os << " for ";
        os << reservation._peopleNo << " ";
        os << (reservation._peopleNo == 1 ? "person." : "people.") << std::endl;
        return os;
    }

    void Reservation::setEmpty() {
        _id = "";
        _name = "";
        _email = "";
        _peopleNo = 0u;
        _day = MIN_DAY;
        _hour = MIN_HOUR;
    }

    std::string Reservation::trim(const std::string &string) {
        size_t first = string.find_first_not_of(' ');
        size_t last = string.find_last_not_of(' ');
        std::string result;
        if (first == last) {
            result = string;
        } else {
            auto index = first;
            last++;
            while (index < last) {
                result += string[index];
                ++index;
            }
        }
        return result;
    }

    std::string Reservation::extract(const std::string &reservation, const char &delimiter, size_t &position) {
        std::string result = "";
        for (auto index = position; index < reservation.length(); ++index) {
            ++position;
            if (reservation[index] != delimiter && reservation[index] != '\n')
                result += reservation[index];
            else break;
        }
        return trim(result);
    }
}
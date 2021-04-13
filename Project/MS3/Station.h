// Name: Hien Dao The Nguyen
// Seneca Student ID: 103 152 195
// Seneca email: hnguyen110@myseneca.ca
// Date of completion: Thursday, April 8, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef MS1_STATION_H
#define MS1_STATION_H

#include <iostream>
#include <string>

namespace sdds {
    class Station {
        size_t _stationID;
        std::string _item;
        std::string _description;
        size_t _nextSerialNumber;
        size_t _stockNumber;
        static size_t _width;
        static size_t _idGenerator;

    public:
        explicit Station(const std::string &information);

        [[nodiscard]] const std::string &getItemName() const;

        size_t getNextSerialNumber();

        [[nodiscard]] size_t getQuantity() const;

        void updateQuantity();

        void display(std::ostream &os, bool full) const;
    };

    inline size_t Station::_width = 0;
    inline size_t Station::_idGenerator = 0;
}

#endif

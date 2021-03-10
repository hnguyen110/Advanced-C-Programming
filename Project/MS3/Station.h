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
        Station(const std::string &information);

        const std::string &getItemName() const;

        size_t getNextSerialNumber();

        size_t getQuantity() const;

        void updateQuantity();

        void display(std::ostream &os, bool full) const;
    };

    inline size_t Station::_width = 0;
    inline size_t Station::_idGenerator = 0;
}

#endif

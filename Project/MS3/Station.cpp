// Name: Hien Dao The Nguyen
// Seneca Student ID: 103 152 195
// Seneca email: hnguyen110@myseneca.ca
// Date of completion: Thursday, April 8, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include "Utilities.h"

namespace sdds {
    Station::Station(const std::string &information) {
        Utilities util;
        size_t position = 0;
        bool more = true;
        _item = util.extractToken(information, position, more);
        _nextSerialNumber = std::stoul(util.extractToken(information, position, more));
        _stockNumber = std::stoul(util.extractToken(information, position, more));
        if (_width < util.getFieldWidth()) _width = util.getFieldWidth();
        _description = util.extractToken(information, position, more);
        _stationID = ++_idGenerator;
    }

    const std::string &Station::getItemName() const {
        return _item;
    }

    size_t Station::getNextSerialNumber() {
        return _nextSerialNumber++;
    }

    size_t Station::getQuantity() const {
        return _stockNumber;
    }

    void Station::updateQuantity() {
        if (_stockNumber != 0) --_stockNumber;
    }

    void Station::display(std::ostream &os, bool full) const {
        os << "[";
        os.width(3);
        os.fill('0');
        os << _stationID;
        os.fill(' ');
        os << "] Item: ";
        os.width(_width);
        os << std::left << _item << " " << std::right;
        os << "[";
        os.width(6);
        os.fill('0');
        os << _nextSerialNumber;
        os.fill(' ');
        os << "]";
        if (full) {
            os << " Quantity: ";
            os.width(_width);
            os << std::left << _stockNumber << std::right;
            os << " Description: " << _description;
        }
        os << std::endl;
    }
}
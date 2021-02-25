/*
 * Purpose: Workshop 4
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Monday Feb/08/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "ConfirmationSender.h"

namespace sdds {
    ConfirmationSender::ConfirmationSender() {
        setEmpty();
    }

    ConfirmationSender &ConfirmationSender::operator+=(const Reservation &reservation) {
        for (auto index = 0u; index < _size; ++index)
            if (_reservations[index] == &reservation) return *this;
        auto temp = _reservations;
        _reservations = new Reservation *[++_size];
        if (temp == nullptr)
            _reservations[_size - 1] = &(const_cast<Reservation &>(reservation));
        else {
            for (auto index = 0u; index < _size - 1; ++index)
                _reservations[index] = temp[index];
            _reservations[_size - 1] = &(const_cast<Reservation &>(reservation));
        }
        delete[] temp;
        return *this;
    }

    ConfirmationSender &ConfirmationSender::operator-=(const Reservation &reservation) {
        for (auto index = 0u; index < _size; ++index) {
            if (_reservations[index] == &reservation) {
                _reservations[index] = nullptr;
                break;
            }
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(const ConfirmationSender &confirmationSender) {
        setEmpty();
        *this = confirmationSender;
    }

    ConfirmationSender &ConfirmationSender::operator=(const ConfirmationSender &confirmationSender) {
        if (this != &confirmationSender) {
            if (_reservations != nullptr) delete _reservations;
            _reservations = new Reservation *[confirmationSender._size];
            _size = confirmationSender._size;
            for (auto index = 0u; index < confirmationSender._size; ++index)
                _reservations[index] = confirmationSender._reservations[index];
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender &&confirmationSender) {
        setEmpty();
        *this = std::move(confirmationSender);
    }

    ConfirmationSender &ConfirmationSender::operator=(ConfirmationSender &&confirmationSender) {
        if (this != &confirmationSender) {
            if (_reservations != nullptr) delete _reservations;
            _reservations = confirmationSender._reservations;
            confirmationSender._reservations = nullptr;
            _size = confirmationSender._size;
            confirmationSender._size = 0;
        }
        return *this;
    }

    ConfirmationSender::~ConfirmationSender() {
        delete[] _reservations;
    }

    std::ostream &operator<<(std::ostream &os, const ConfirmationSender &confirmationSender) {
        os << "--------------------------" << std::endl;
        os << "Confirmations to Send" << std::endl;
        os << "--------------------------" << std::endl;
        if (confirmationSender._reservations == nullptr)
            os << "There are no confirmations to send!" << std::endl;
        else
            for (auto index = 0u; index < confirmationSender._size; ++index)
                if (confirmationSender._reservations[index] != nullptr)
                    os << *confirmationSender._reservations[index];
        os << "--------------------------" << std::endl;
        return os;
    }

    void ConfirmationSender::setEmpty() {
        _reservations = nullptr;
        _size = 0;
    }
}
// Name: Hien Dao The Nguyen
// Seneca Student ID: 103 152 195
// Seneca email: hnguyen110@myseneca.ca
// Date of completion: Thursday, April 8, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

namespace sdds {
    std::deque<CustomerOrder> pending;
    std::deque<CustomerOrder> completed;
    std::deque<CustomerOrder> incomplete;

    Workstation::Workstation(const std::string &order) : Station(order) {
        _next = nullptr;
    }

    void Workstation::fill(std::ostream &os) {
        if (!_orders.empty())
            _orders.front().fillItem(*this, os);
    }

    bool Workstation::attemptToMoveOrder() {
        bool moved = false;
        if (!_orders.empty()) {
            if (_orders.front().isItemFilled(getItemName())) {
                if (_next != nullptr) {
                    *_next += std::move(_orders.front());
                } else {
                    if (_orders.front().isFilled()) {
                        completed.emplace_back(std::move(_orders.front()));
                    } else {
                        incomplete.emplace_back(std::move(_orders.front()));
                    }
                }
                _orders.pop_front();
                moved = true;
            } else {
                if (!getQuantity()) {
                    if (_next != nullptr) {
                        *_next += std::move(_orders.front());
                    } else {
                        incomplete.emplace_back(std::move(_orders.front()));
                    }
                    _orders.pop_front();
                    moved = true;
                }
            }
        }
        return moved;
    }

    void Workstation::setNextStation(Workstation *station) {
        _next = station;
    }

    const Workstation *Workstation::getNextStation() const {
        return _next;
    }

    void Workstation::display(std::ostream &os) const {
        os << this->getItemName();
        os << " --> ";
        os << (_next != nullptr ? _next->getItemName() : "End of Line");
        os << std::endl;
    }

    Workstation &Workstation::operator+=(CustomerOrder &&order) {
        _orders.emplace_back(std::move(order));
        return *this;
    }
}
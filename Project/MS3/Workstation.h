// Name: Hien Dao The Nguyen
// Seneca Student ID: 103 152 195
// Seneca email: hnguyen110@myseneca.ca
// Date of completion: Thursday, April 8, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef MS3_WORKSTATION_H
#define MS3_WORKSTATION_H

#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {
    extern std::deque<CustomerOrder> pending;
    extern std::deque<CustomerOrder> completed;
    extern std::deque<CustomerOrder> incomplete;

    class Workstation : public Station {
        std::deque<CustomerOrder> _orders;
        Workstation *_next;

    public:
        explicit Workstation(const std::string &order);

        void fill(std::ostream &os);

        bool attemptToMoveOrder();

        void setNextStation(Workstation *station);

        [[nodiscard]] const Workstation *getNextStation() const;

        void display(std::ostream &os) const;

        Workstation &operator+=(CustomerOrder &&order);
    };
}

#endif

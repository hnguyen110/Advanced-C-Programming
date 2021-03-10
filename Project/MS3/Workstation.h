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

        // For testing only
//        [[nodiscard]] size_t retrieveOrdersSize() const {
//            return _orders.size();
//        }
//
//        [[nodiscard]] bool isOrdersEmpty() const {
//            return _orders.empty();
//        }
//
//        [[nodiscard]] bool isItemFilled(const std::string &str) const {
//            return _orders.front().isItemFilled(str);
//        }
//
//        [[nodiscard]] bool isFilled() const {
//            return _orders.front().isFilled();
//        }
    };
}

#endif

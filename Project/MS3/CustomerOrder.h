// Name: Hien Dao The Nguyen
// Seneca Student ID: 103 152 195
// Seneca email: hnguyen110@myseneca.ca
// Date of completion: Thursday, April 8, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef MS2_CUSTOMER_ORDER_H
#define MS2_CUSTOMER_ORDER_H

#include <iostream>
#include <string>
#include <utility>
#include "Station.h"

namespace sdds {
    struct Item {
        std::string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        explicit Item(std::string src) : m_itemName(std::move(src)) {};
    };

    class CustomerOrder {
        std::string _customerName;
        std::string _productName;
        size_t _quantity;
        Item **_items;
        static size_t _width;

    public:
        CustomerOrder();

        explicit CustomerOrder(const std::string &information);

        CustomerOrder(const CustomerOrder &order);

        CustomerOrder &operator=(const CustomerOrder &) = delete;

        CustomerOrder(CustomerOrder &&order) noexcept;

        CustomerOrder &operator=(CustomerOrder &&order) noexcept;

        ~CustomerOrder();

        [[nodiscard]] bool isFilled() const;

        [[nodiscard]] bool isItemFilled(const std::string &itemName) const;

        void fillItem(Station &station, std::ostream &os);

        void display(std::ostream &os) const;

    private:
        void clear();

        void setEmpty();
    };

    inline size_t CustomerOrder::_width = 0;
}

#endif

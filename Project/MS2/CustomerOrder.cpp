#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds {
    CustomerOrder::CustomerOrder() {
        setEmpty();
    }

    CustomerOrder::CustomerOrder(const std::string &information) {
        Utilities util;
        size_t position = 0;
        bool more = true;
        setEmpty();
        _customerName = util.extractToken(information, position, more);
        _productName = util.extractToken(information, position, more);
        while (more) {
            auto part = util.extractToken(information, position, more);
            if (_items == nullptr) {
                if (part.length()) {
                    _items = new Item *[++_quantity];
                    _items[_quantity - 1] = new Item(part);
                } else throw std::string("Part can not be empty");
            } else {
                Item **temp = _items;
                _items = new Item *[++_quantity];
                for (size_t index = 0; index < _quantity - 1; ++index)
                    _items[index] = temp[index];
                _items[_quantity - 1] = new Item(part);
                delete[] temp;
            }
            if (_width < util.getFieldWidth()) _width = util.getFieldWidth();
        }
    }

    CustomerOrder::CustomerOrder(const CustomerOrder &order) {
        throw std::string("Cannot make copies");
    }

    CustomerOrder::CustomerOrder(CustomerOrder &&order) noexcept {
        setEmpty();
        *this = std::move(order);
    }

    CustomerOrder &CustomerOrder::operator=(CustomerOrder &&order) noexcept {
        if (_items != nullptr) clear();
        _customerName = order._customerName;
        _productName = order._productName;
        _quantity = order._quantity;
        _items = order._items;
        order.setEmpty();
        return *this;
    }

    CustomerOrder::~CustomerOrder() { clear(); }

    bool CustomerOrder::isFilled() const {
        for (size_t index = 0; index < _quantity; ++index)
            if (!_items[index]->m_isFilled) return false;
        return true;
    }

    bool CustomerOrder::isItemFilled(const std::string &itemName) const {
        for (size_t index = 0; index < _quantity; ++index) {
            if (_items[index]->m_itemName == itemName)
                if (_items[index]->m_isFilled)
                    return true;
        }
        return false;
    }

    void CustomerOrder::fillItem(Station &station, std::ostream &os) {
        for (size_t index = 0; index < _quantity; ++index) {
            if (_items[index]->m_itemName == station.getItemName()) {
                if (station.getQuantity()) {
                    _items[index]->m_isFilled = true;
                    _items[index]->m_serialNumber = station.getNextSerialNumber();
                    station.updateQuantity();
                    os << "    Filled ";
                } else os << "    Unable to fill ";
                os << _customerName;
                os << ", ";
                os << _productName << " ";
                os << "[" << _items[index]->m_itemName << "]";
                os << std::endl;
            }
        }
    }

    void CustomerOrder::display(std::ostream &os) const {
        os << _customerName << " - " << _productName << std::endl;
        for (size_t index = 0; index < _quantity; ++index) {
            os << "[";
            os.width(6);
            os.fill('0');
            os << _items[index]->m_serialNumber;
            os.fill(' ');
            os << "]";
            os << " ";
            os.width(_width);
            os << std::left << _items[index]->m_itemName << std::right;
            os << " - ";
            if (_items[index]->m_isFilled)
                os << "FILLED";
            else
                os << "TO BE FILLED";
            os << std::endl;
        }
    }

    void CustomerOrder::clear() {
        for (size_t index = 0; index < _quantity; ++index)
            delete _items[index];
        delete[] _items;
    }

    void CustomerOrder::setEmpty() {
        _customerName = "";
        _productName = "";
        _quantity = 0;
        _items = nullptr;
    }
}
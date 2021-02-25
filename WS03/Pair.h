/*
 * Purpose: Workshop 3
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/05/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS03_PAIR_H
#define WS03_PAIR_H

#include <iostream>

namespace sdds {
    template<typename Value, typename Key>
    class Pair {
        Key _key;
        Value _value;

    public:
        Pair() {}

        Pair(const Key &key, const Value &value) {
            _key = key;
            _value = value;
        }

        const Value &value() const { return _value; }

        const Key &key() const { return _key; }

        virtual void display(std::ostream &os) const { os << key() << " : " << value() << std::endl; }

        friend std::ostream &operator<<(std::ostream &os, const Pair<Value, Key> &pair) {
            pair.display(os);
            return os;
        }
    };
}


#endif

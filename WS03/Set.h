/*
 * Purpose: Workshop 3
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/05/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS03_SET_H
#define WS03_SET_H

#include <iostream>

namespace sdds {
    template<size_t capacity, typename GenericType>
    class Set {
        size_t _elementNo;
        GenericType _collection[capacity];

    public:
        size_t size() const {
            return _elementNo;
        }

        const GenericType &get(size_t index) const {
            return _collection[index];
        }

        void operator+=(const GenericType &item) {
            if (_elementNo != capacity) {
                _collection[_elementNo++] = item;
            }
        }
    };
}


#endif

/*
 * Purpose: Workshop 3
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/05/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS03_SET_SUMMABLE_H
#define WS03_SET_SUMMABLE_H

#include "Set.h"

namespace sdds {
    template<size_t capacity, typename GenericType>
    class SetSummable : public Set<capacity, GenericType> {
    public:
        SetSummable() : Set<capacity, GenericType>() {}

        GenericType accumulate(const std::string &filter) const {
            GenericType accumulator(filter);
            for (auto index = 0u; index < SetSummable<capacity, GenericType>::size(); ++index) {
                if (accumulator.isCompatibleWith(SetSummable<capacity, GenericType>::get(index))) {
                    accumulator += SetSummable<capacity, GenericType>::get(index);
                }
            }
            return accumulator;
        }
    };
}


#endif

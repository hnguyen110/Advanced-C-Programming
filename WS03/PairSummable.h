/*
 * Purpose: Workshop 3
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/05/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS03_PAIR_SUMMABLE_H
#define WS03_PAIR_SUMMABLE_H

#include "Pair.h"

namespace sdds {
    template<typename Value, typename Key>
    class PairSummable : public Pair<Value, Key> {
        static Value _value;
        static size_t _fieldWidth;

    public:
        PairSummable() : Pair<Value, Key>() {};

        PairSummable(const Key &key, const Value &value = Value())
                : Pair<Value, Key>(key, value) {
            if (Pair<Value, Key>::key().size() > _fieldWidth) _fieldWidth = Pair<Value, Key>::key().size();
        }

        bool isCompatibleWith(const PairSummable<Value, Key> &otherPair) const {
            return otherPair.key() == Pair<Value, Key>::key();
        }

        PairSummable &operator+=(const PairSummable &other) {
            *this = PairSummable(PairSummable<Value, Key>::key(),
                                 PairSummable<Value, Key>::value() + other.value());
            return *this;
        }

        void display(std::ostream &os) const {
            os.width(_fieldWidth);
            os << std::left;
            Pair<Value, Key>::display(os);
            os << std::right;
        }
    };

    template<>
    inline PairSummable<std::string, std::string> &
    PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string> &other) {
        auto value = PairSummable<std::string, std::string>::value()
                     + (PairSummable<std::string, std::string>::value() != "" ? ", " : "")
                                                                                      + other.value();
        *this = PairSummable(PairSummable<std::string, std::string>::key(), value);
        return *this;
    }

    template<typename Value, typename Key>
    inline size_t PairSummable<Value, Key>::_fieldWidth = 0;
}


#endif

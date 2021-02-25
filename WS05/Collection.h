/*
 * Purpose: Workshop 5
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS05_COLLECTION_H
#define WS05_COLLECTION_H

#include <string>
#include <stdexcept>

namespace sdds {
    template<typename GenericType>
    class Collection {
        std::string _collectionName;
        GenericType **_collection;
        size_t _size;

        void (*_observer)(const Collection<GenericType> &, const GenericType &);

    public:
        Collection(const std::string &name) {
            _collectionName = name;
            _collection = nullptr;
            _observer = nullptr;
            _size = 0;
        }

        Collection(const Collection &) = delete;

        Collection &operator=(const Collection &) = delete;

        ~Collection() {
            for (size_t index = 0; index < _size; ++index)
                delete _collection[index];
            delete[] _collection;
        };

        const std::string &name() const { return _collectionName; }

        size_t size() const { return _size; }

        void setObserver(void (*observer)(const Collection<GenericType> &, const GenericType &)) {
            _observer = observer;
        }

        Collection<GenericType> &operator+=(const GenericType &item) {
            for (size_t index = 0; index < _size; ++index)
                if (_collection[index]->title() == item.title()) return *this;
            GenericType **temp = _collection;
            _collection = new GenericType *[_size + 1];
            for (size_t index = 0; index < _size; ++index)
                _collection[index] = temp[index];
            _collection[_size++] = new GenericType(item);
            if (_observer != nullptr) _observer(*this, item);
            delete[] temp;
            return *this;
        }

        GenericType &operator[](size_t index) const {
            if (index >= 0 && index < _size)
                return *(_collection[index]);
            else
                throw std::out_of_range(
                        "Bad index [" + std::to_string(index) + "]. " + "Collection has [" + std::to_string(size()) +
                        "] items.");
        }

        GenericType *operator[](const std::string &title) const {
            for (size_t index = 0; index < _size; ++index)
                if (_collection[index]->title() == title)
                    return (_collection[index]);
            return nullptr;
        }

        friend std::ostream &operator<<(std::ostream &os, const Collection &collection) {
            for (size_t index = 0; index < collection._size; ++index)
                os << *(collection._collection[index]);
            return os;
        }
    };
}


#endif

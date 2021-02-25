#include "Bouquet.h"

Bouquet::Bouquet() {
    _flowerNames = nullptr;
    _flowerNo = 0;
    ++_bouquetCounter;
}

Bouquet::Bouquet(std::string *flowerName, size_t flowerNo) {
    if (flowerName == nullptr && flowerNo != 0) {
        throw std::string("Bad Parameters");
    } else {
        _flowerNo = flowerNo;
        _flowerNames = nullptr;
        if (flowerName != nullptr && flowerNo != 0) {
            _flowerNames = new std::string[flowerNo];
            for (size_t index = 0; index < flowerNo; ++index)
                _flowerNames[index] = flowerName[index];
        }
        ++_bouquetCounter;
    }
}

Bouquet::~Bouquet() {
    delete[] _flowerNames;
    _flowerNames = nullptr;
    --_bouquetCounter;
}

bool Bouquet::operator==(const Bouquet &bouquet) const {
    bool state = false;
    if (isEmpty() || bouquet.isEmpty()) {
        delete[] _flowerNames;
        delete[] bouquet._flowerNames;
        exit(20);
    }
    if (hasFlower("Poison Ivy", *this)) throw 1;
    if (hasFlower("Poisong Ivy", *this)) throw 2;
    if (_flowerNo == bouquet._flowerNo) {
        state = true;
        for (size_t index = 0; index < _flowerNo; ++index) {
            if (_flowerNames[index] != bouquet._flowerNames[index]) {
                state = false;
                break;
            }
        }
    }
    return state;
}

bool Bouquet::hasFlower(const std::string &name, const Bouquet &bouquet) const {
    bool state = false;
    if (bouquet._flowerNames != nullptr && bouquet._flowerNo != 0) {
        for (size_t index = 0; index < bouquet._flowerNo; ++index) {
            if (_flowerNames[index] == name) {
                state = true;
                break;
            }
        }
    }
    return state;
}

bool Bouquet::isEmpty() const {
    bool state = false;
    if (_flowerNames == nullptr) {
        if (_flowerNo == 0) {
            state = true;
        }
    }
    return state;
}



//// Header file
//
//#ifndef CUSTOM_TYPE_BOUQUET_H
//#define CUSTOM_TYPE_BOUQUET_H
//
//#include <iostream>
//#include <string>
//
//class Bouquet {
//    std::string *_flowerNames;
//    size_t _flowerNo;
//    static size_t _bouquetCounter;
//
//public:
//    Bouquet();
//
//    Bouquet(std::string *flowerName, size_t flowerNo);
//
//    ~Bouquet();
//
//    bool operator==(const Bouquet &bouquet) const;
//
//public:
//    bool hasFlower(const std::string &name, const Bouquet &bouquet) const;
//
//    bool isEmpty() const;
//
//    static size_t getBouquetCounter() { return _bouquetCounter; }
//};
//
//inline size_t Bouquet::_bouquetCounter = 0;
//
//#endif
//
//
//
//// CPP file
//
//#include "Bouquet.h"
//
//Bouquet::Bouquet() {
//    _flowerNames = nullptr;
//    _flowerNo = 0;
//    ++_bouquetCounter;
//}
//
//Bouquet::Bouquet(std::string *flowerName, size_t flowerNo) {
//    if (flowerName == nullptr && flowerNo != 0) {
//        throw std::string("Bad Parameters");
//    } else {
//        _flowerNo = flowerNo;
//        _flowerNames = nullptr;
//        if (flowerName != nullptr && flowerNo != 0) {
//            _flowerNames = new std::string[flowerNo];
//            for (size_t index = 0; index < flowerNo; ++index)
//                _flowerNames[index] = flowerName[index];
//        }
//        ++_bouquetCounter;
//    }
//}
//
//Bouquet::~Bouquet() {
//    delete[] _flowerNames;
//    _flowerNames = nullptr;
//    --_bouquetCounter;
//}
//
//bool Bouquet::operator==(const Bouquet &bouquet) const {
//    bool state = false;
//    if (isEmpty() || bouquet.isEmpty()) {
//        delete[] _flowerNames;
//        delete[] bouquet._flowerNames;
//        exit(20);
//    }
//    if (hasFlower("Poison Ivy", *this)) throw 1;
//    if (hasFlower("Poisong Ivy", *this)) throw 2;
//    if (_flowerNo == bouquet._flowerNo) {
//        state = true;
//        for (size_t index = 0; index < _flowerNo; ++index) {
//            if (_flowerNames[index] != bouquet._flowerNames[index]) {
//                state = false;
//                break;
//            }
//        }
//    }
//    return state;
//}
//
//bool Bouquet::hasFlower(const std::string &name, const Bouquet &bouquet) const {
//    bool state = false;
//    if (bouquet._flowerNames != nullptr && bouquet._flowerNo != 0) {
//        for (size_t index = 0; index < bouquet._flowerNo; ++index) {
//            if (_flowerNames[index] == name) {
//                state = true;
//                break;
//            }
//        }
//    }
//    return state;
//}
//
//bool Bouquet::isEmpty() const {
//    bool state = false;
//    if (_flowerNames == nullptr) {
//        if (_flowerNo == 0) {
//            state = true;
//        }
//    }
//    return state;
//}












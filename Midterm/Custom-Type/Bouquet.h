#ifndef CUSTOM_TYPE_BOUQUET_H
#define CUSTOM_TYPE_BOUQUET_H

#include <iostream>
#include <string>

class Bouquet {
    std::string *_flowerNames;
    size_t _flowerNo;
    static size_t _bouquetCounter;

public:
    Bouquet();

    Bouquet(std::string *flowerName, size_t flowerNo);

    ~Bouquet();

    bool operator==(const Bouquet &bouquet) const;

public:
    bool hasFlower(const std::string &name, const Bouquet &bouquet) const;

    bool isEmpty() const;

    static size_t getBouquetCounter() { return _bouquetCounter; }
};

inline size_t Bouquet::_bouquetCounter = 0;

#endif
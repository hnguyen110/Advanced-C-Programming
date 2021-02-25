/*
 * Purpose: Workshop 5
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS05_BOOK_H
#define WS05_BOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Utils.h"

namespace sdds {
    class Book {
        std::string _author;
        std::string _title;
        std::string _publicationCountry;
        size_t _publicationYear;
        double _price;
        std::string _description;

    public:
        Book();

        Book(const std::string &);

        const std::string &title() const;

        const std::string &country() const;

        const size_t &year() const;

        double &price();

        friend std::ostream &operator<<(std::ostream &os, const Book &book);

        template<typename GenericType>
        void fixSpelling(GenericType &spellChecker) {
            spellChecker(_description);
        }
    };
}

#endif

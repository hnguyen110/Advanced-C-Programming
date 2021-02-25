/*
 * Purpose: Workshop 5
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Book.h"

namespace sdds {
    Book::Book() {}

    Book::Book(const std::string &book) {
        size_t index = 0u;
        _author = Utils::extract(book, ',', index);
        _title = Utils::extract(book, ',', index);
        _publicationCountry = Utils::extract(book, ',', index);
        _price = std::stod(Utils::extract(book, ',', index));
        _publicationYear = std::stoul(Utils::extract(book, ',', index));
        _description = Utils::extract(book, '\n', index);
    }

    const std::string &Book::title() const {
        return _title;
    }

    const std::string &Book::country() const {
        return _publicationCountry;
    }

    const size_t &Book::year() const {
        return _publicationYear;
    }

    double &Book::price() {
        return _price;
    }

    std::ostream &operator<<(std::ostream &os, const Book &book) {
        os.width(20);
        os << book._author;
        os << " | ";
        os.width(22);
        os << book._title;
        os << " | ";
        os.width(5);
        os << book._publicationCountry;
        os << " | ";
        os.width(4);
        os << book._publicationYear;
        os << " | ";
        os.width(6);
        os << std::fixed << std::setprecision(2);
        os << book._price;
        os << " | ";
        os << book._description << std::endl;
        return os;
    }
}


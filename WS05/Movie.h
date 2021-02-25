/*
 * Purpose: Workshop 5
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS05_MOVIE_H
#define WS05_MOVIE_H

#include <string>
#include <iostream>
#include "Utils.h"

namespace sdds {
    class Movie {
        std::string _title;
        size_t _releaseYear;
        std::string _description;

    public:
        Movie();

        const std::string &title() const;

        Movie(const std::string &strMovie);

        template<typename GenericType>
        void fixSpelling(GenericType &spellChecker) {
            spellChecker(_title);
            spellChecker(_description);
        }

        friend std::ostream &operator<<(std::ostream &os, const Movie &movie);
    };
}


#endif
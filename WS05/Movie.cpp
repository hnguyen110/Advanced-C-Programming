/*
 * Purpose: Workshop 5
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Movie.h"

namespace sdds {
    Movie::Movie() {
        _title = "";
        _releaseYear = 0;
        _description = "";
    }

    Movie::Movie(const std::string &strMovie) {
        size_t position = 0;
        _title = Utils::extract(strMovie, ',', position);
        _releaseYear = std::stoul(Utils::extract(strMovie, ',', position));
        _description = Utils::extract(strMovie, '\n', position);
    }

    const std::string &Movie::title() const {
        return _title;
    }

    std::ostream &operator<<(std::ostream &os, const Movie &movie) {
        os.width(40);
        os << movie.title();
        os << " | ";
        os.width(4);
        os << movie._releaseYear;
        os << " | ";
        os << movie._description << std::endl;
        return os;
    }
}

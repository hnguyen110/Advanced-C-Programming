/*
 * Purpose: Workshop 7
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Mar/17/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS07_SONG_COLLECTION_H
#define WS07_SONG_COLLECTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iomanip>

namespace sdds {
    std::string trim(const std::string &string);

    std::string formatTime(const size_t &lengthOfSong);

    struct Song {
        std::string m_artist;
        std::string m_title;
        std::string m_album;
        double m_price;
        std::string m_releaseYear;
        size_t m_length;
    };

    class SongCollection {
        std::vector<Song> _collection;

    public:
        explicit SongCollection(const char *filename);

        void display(std::ostream &out) const;

        void sort(const std::string &option);

        void cleanAlbum();

        [[nodiscard]] bool inCollection(const std::string &artistName) const;

        [[nodiscard]] std::list<Song> getSongsForArtist(const std::string &artistName) const;
    };

    std::ostream &operator<<(std::ostream &out, const Song &theSong);
}

#endif

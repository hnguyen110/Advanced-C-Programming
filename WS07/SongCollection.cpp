/*
 * Purpose: Workshop 7
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Mar/17/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "SongCollection.h"

namespace sdds {
    SongCollection::SongCollection(const char *filename) {
        if (filename != nullptr) {
            std::ifstream dataFile(filename);
            if (dataFile.is_open()) {
                Song song;
                char buffer[256];
                while (dataFile.good()) {
                    dataFile.getline(buffer, 26);
                    song.m_title = trim(buffer);
                    dataFile.clear();

                    dataFile.getline(buffer, 26);
                    song.m_artist = trim(buffer);
                    dataFile.clear();

                    dataFile.getline(buffer, 26);
                    song.m_album = (!trim(buffer).empty() ? trim(buffer) : "[None]");
                    dataFile.clear();

                    dataFile.getline(buffer, 6);
                    song.m_releaseYear = trim(buffer);
                    dataFile.clear();

                    dataFile.getline(buffer, 6);
                    song.m_length = std::stoul(trim(buffer));
                    dataFile.clear();

                    dataFile.getline(buffer, 6, '\n');
                    song.m_price = std::stod(trim(buffer));

                    _collection.emplace_back(song);
                }
            }
        }
    }

    void SongCollection::display(std::ostream &out) const {
        size_t total = std::accumulate(_collection.begin(),
                                       _collection.end(),
                                       0, [=](size_t init, const Song &first) {
                    return first.m_length + init;
                });

        std::for_each(_collection.begin(),
                      _collection.end(),
                      [=, &out](const Song &song) {
                          out << song << std::endl;
                      });

        out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
        out << "| " << std::setw(77) << "Total Listening Time: " << formatTime(total) << " |";
        out << std::endl;
    }

    void SongCollection::sort(const std::string &option) {
        if (option == "title") {
            std::sort(_collection.begin(),
                      _collection.end(),
                      [=](const Song &first, const Song &second) {
                          return first.m_title < second.m_title;
                      });

        } else if (option == "album") {
            std::sort(_collection.begin(),
                      _collection.end(),
                      [=](const Song &first, const Song &second) {
                          return first.m_album < second.m_album;
                      });

        } else if (option == "length") {
            std::sort(_collection.begin(),
                      _collection.end(),
                      [=](const Song &first, const Song &second) {
                          return first.m_length < second.m_length
                                 || (first.m_length == second.m_length
                                     && first.m_price < second.m_price);
                      });
        } else {
            throw std::string("Invalid option");
        }
    }

    void SongCollection::cleanAlbum() {
        std::for_each(_collection.begin(),
                      _collection.end(),
                      [=](Song &song) {
                          if (song.m_album == "[None]") song.m_album = "";
                      });
    }

    bool SongCollection::inCollection(const std::string &artistName) const {
        auto iterator = std::find_if(_collection.begin(),
                                     _collection.end(),
                                     [=](const Song &song) { return song.m_artist == artistName; });

        return iterator != _collection.end();
    }

    std::list<Song> SongCollection::getSongsForArtist(const std::string &artistName) const {
        std::list<Song> songs;
        std::copy_if(_collection.begin(),
                     _collection.end(),
                     std::back_inserter(songs),
                     [=](const Song &song) { return song.m_artist == artistName; });

        return songs;
    }

    std::ostream &operator<<(std::ostream &out, const Song &song) {
        out << "| ";
        out << std::setw(20) << std::left << song.m_title << " | ";
        out << std::setw(15) << song.m_artist << " | ";
        out << std::setw(20) << song.m_album << " | ";
        out << std::setw(6) << std::right << song.m_releaseYear << " | ";
        out << formatTime(song.m_length) << " | ";
        out << song.m_price;
        out << " |";;
        return out;
    }

    std::string trim(const std::string &string) {
        size_t first = string.find_first_not_of(' ');
        size_t last = string.find_last_not_of(' ');
        std::string result;
        auto index = first;
        last++;
        while (index < last) {
            if (string[index] == '\0') break;
            result += string[index];
            ++index;
        }
        return result;
    }

    std::string formatTime(const size_t &lengthOfSong) {
        std::string result;
        if (lengthOfSong / 3600 != 0) {
            result += std::to_string(lengthOfSong / 3600);
            result += ":";
        }
        if (lengthOfSong % 3600 / 60 != 0) {
            result += std::to_string(lengthOfSong % 3600 / 60);
            result += ":";
        }
        if (std::to_string(lengthOfSong % 60).length() == 1) {
            result += "0";
        }
        result += std::to_string(lengthOfSong % 60);
        return result;
    }
}
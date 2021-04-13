/*
 * Purpose: Workshop 6
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Mar/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "Utilities.h"

namespace sdds {
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


    std::string extract(std::istream &is, const char &delimiter) {
        std::string result;
        char buffer;
        while (true) {
            buffer = is.get();
            if (buffer == delimiter || buffer == '\n' || buffer == -1)
                break;
            else result += buffer;
        }
        return trim(result);
    }

    bool isEmptyOrWhiteSpace(const std::string &string) {
        if (!string.empty()) {
            for (auto &each : string) {
                if (each != ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    bool isNumber(const std::string &string) {
        if (string.empty()) return false;
        for (auto &each : string) {
            if (!isdigit(each)) {
                return false;
            }
        }
        return true;
    }

    Vehicle *createInstance(std::istream &istream) {
        char buffer[256];
        istream.getline(buffer, 255, ',');

        auto _tag = trim(buffer);
        if (_tag == "c" || _tag == "C") {
            try {
                return new Car(istream);
            } catch (std::string& err) {
                std::cout << err << std::endl;
                return nullptr;
            }
        }
        else if (_tag == "r" || _tag == "R")
            try {
                return new Racecar(istream);
            } catch (std::string& err) {
                std::cout << err << std::endl;
                return nullptr;
            }
        else
        {
            istream.clear();
            istream.ignore(2000, '\n');
            throw std::string("Unrecognized record type: [") + _tag + std::string("]");
        }
    }
}
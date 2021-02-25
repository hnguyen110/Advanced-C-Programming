/*
 * Purpose: Workshop 5
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS05_UTILS_H
#define WS05_UTILS_H

#include <string>

namespace sdds {
    class Utils {
    public:
        static std::string trim(const std::string &string) {
            size_t first = string.find_first_not_of(' ');
            size_t last = string.find_last_not_of(' ');
            std::string result;
            if (first == last) {
                result = string;
            } else {
                auto index = first;
                last++;
                while (index < last) {
                    result += string[index];
                    ++index;
                }
            }
            return result;
        }

        static std::string extract(const std::string &string, const char &delimiter, size_t &position) {
            std::string result = "";
            for (auto index = position; index < string.length(); ++index) {
                ++position;
                if (string[index] != delimiter && string[index] != '\n')
                    result += string[index];
                else break;
            }
            return trim(result);
        }
    };
}


#endif

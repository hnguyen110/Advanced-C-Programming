/*
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Sunday Jan/24/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#include "event.h"

size_t g_sysClock = 0;

namespace sdds {
    Event::Event() {
        eventDescription = nullptr;
        startingTime = 0;
    }

    Event::Event(const Event &copy) {
        eventDescription = nullptr;
        *this = copy;
    }

    Event &Event::operator=(const Event &copy) {
        if (this != &copy) {
            set(copy.eventDescription);
            startingTime = copy.startingTime;
        }
        return *this;
    }

    Event::~Event() {
        delete[] eventDescription;
        eventDescription = nullptr;
    }

    void Event::display() const {
        static size_t counter = 0;
        std::cout.width(2);
        std::cout << ++counter << ". ";
        if (eventDescription != nullptr) {
            formatTime(startingTime);
            std::cout << " => " << eventDescription;
        } else
            std::cout << "| No Event |";
        std::cout << std::endl;
    }

    void Event::set(const char *description) {
        if (eventDescription != nullptr) delete[] eventDescription;
        if (description == nullptr) {
            eventDescription = nullptr;
            startingTime = 0;
        } else {
            eventDescription = new char[strlen(description) + 1];
            strcpy(eventDescription, description);
            startingTime = g_sysClock;
        }
    }

    void Event::formatTime(const size_t startTime) {
        auto hours = startTime / 3600;
        auto minutes = startTime % 3600 / 60;
        auto seconds = startTime % 3600 % 60;
        std::cout.fill('0');
        std::cout.width(2);
        std::cout << hours << ":";
        std::cout.width(2);
        std::cout << minutes << ":";
        std::cout.width(2);
        std::cout << seconds;
        std::cout.fill(' ');
    }
}
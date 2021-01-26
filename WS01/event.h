/*
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Sunday Jan/24/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS01_EVENT_H
#define WS01_EVENT_H

#include <iostream>
#include <cstring>

extern size_t g_sysClock;

namespace sdds {
    class Event {
    private:
        char* eventDescription;
        size_t startingTime;

    public:
        Event();

        Event(const Event &copy);

        Event &operator=(const Event &event);

        ~Event();

        void display() const;

        void set(const char *description = nullptr);

    private:
        static void formatTime(const size_t startTime);
    };
}

#endif
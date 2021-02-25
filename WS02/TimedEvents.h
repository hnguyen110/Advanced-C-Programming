/*
 * Purpose: Workshop 2
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Sunday Jan/28/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

#ifndef WS02_TIMED_EVENTS_H
#define WS02_TIMED_EVENTS_H

#include <iostream>
#include <string>
#include <chrono>

namespace sdds {
    class TimedEvents {
        size_t recordNo;
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point endTime;

        static constexpr const size_t MAX_EVENT_NUMBER = 10;
        static constexpr const char DEFAULT_UNIT_OF_TIME[] = "nanoseconds";
        struct Event {
            std::string eventName;
            std::string unitOfTime;
            std::chrono::steady_clock::duration duration;
        };
        Event events[MAX_EVENT_NUMBER];

    public:
        TimedEvents();

        void startClock();

        void stopClock();

        void addEvent(const char *eventName);

        friend std::ostream &operator<<(std::ostream &os, const TimedEvents &timedEvents);
    };
}

#endif
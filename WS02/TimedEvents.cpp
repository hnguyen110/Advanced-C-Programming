#include "TimedEvents.h"

namespace sdds {
    TimedEvents::TimedEvents() {
        recordNo = 0;
        startTime = std::chrono::steady_clock::now();
        endTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::startClock() {
        startTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::stopClock() {
        endTime = std::chrono::steady_clock::now();
    }

    void TimedEvents::addEvent(const char *eventName) {
        if (eventName != nullptr) {
            events[recordNo].eventName = eventName;
            events[recordNo].unitOfTime = DEFAULT_UNIT_OF_TIME;
            events[recordNo].duration = endTime - startTime;
            ++recordNo;
        }
    }

    std::ostream &operator<<(std::ostream &os, const TimedEvents &timedEvents) {
        os << "--------------------------" << std::endl;
        os << "Execution Times:" << std::endl;
        os << "--------------------------" << std::endl;
        for (auto cnt = 0u; cnt < timedEvents.recordNo; ++cnt) {
            os.width(21);
            os << std::left << timedEvents.events[cnt].eventName;
            os.width(13);
            os << std::right
               << std::chrono::duration_cast<std::chrono::nanoseconds>(timedEvents.events[cnt].duration).count();
            os << " ";
            os << timedEvents.events[cnt].unitOfTime << std::endl;
        }
        os << "--------------------------" << std::endl;
        return os;
    }
}
#ifndef MS3_LINE_MANAGER_H
#define MS3_LINE_MANAGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Workstation.h"

namespace sdds {
    class LineManager {
        std::vector<Workstation *> _workstations;
        size_t _orderNo;
        Workstation *_firstStation;
        size_t _iteration;

    public:
        LineManager(const std::string &file, const std::vector<Workstation *> &stations);

        void linkStations();

        bool run(std::ostream &os);

        void display(std::ostream &os) const;

        Workstation *firstStation() const;

        bool isNextStation(const Workstation *workstation) const;
    };
}

#endif

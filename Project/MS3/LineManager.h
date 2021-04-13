// Name: Hien Dao The Nguyen
// Seneca Student ID: 103 152 195
// Seneca email: hnguyen110@myseneca.ca
// Date of completion: Thursday, April 8, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef MS3_LINE_MANAGER_H
#define MS3_LINE_MANAGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <unordered_map>
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

        [[nodiscard]] Workstation *firstStation() const;
    };
}

#endif

// Name: Hien Dao The Nguyen
// Seneca Student ID: 103 152 195
// Seneca email: hnguyen110@myseneca.ca
// Date of completion: Thursday, April 8, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"
#include "Utilities.h"

namespace sdds {
    LineManager::LineManager(const std::string &file, const std::vector<Workstation *> &stations) {
        _orderNo = pending.size();
        _iteration = 0;
        _firstStation = nullptr;
        sdds::Utilities::setDelimiter('|');
        Utilities util;
        std::ifstream configFile(file);
        std::for_each(stations.begin(), stations.end(), [&](Workstation *station) {
            station->setNextStation(nullptr);
        });
        if (configFile.is_open()) {
            std::string buffer;
            while (configFile.good()) {
                std::getline(configFile, buffer);
                size_t position = 0;
                bool more = true;
                std::string token = util.extractToken(buffer, position, more);
                std::for_each(stations.begin(), stations.end(), [&](Workstation *station) {
                    if (station->getItemName() == token)
                        _workstations.emplace_back(station);
                });
                if (buffer.find(Utilities::getDelimiter()) != std::string::npos) {
                    auto firstStation = std::find_if(stations.begin(), stations.end(), [&](Workstation *station) {
                        return station->getItemName() == token;
                    });
                    token = util.extractToken(buffer, position, more);
                    auto secondStation = std::find_if(stations.begin(), stations.end(), [&](Workstation *station) {
                        return station->getItemName() == token;
                    });
                    (*firstStation)->setNextStation(*secondStation);
                    position = 0;
                }
            }
        } else {
            throw std::string("Can not open station config file");
        }
        _firstStation = firstStation();
    }

    void LineManager::linkStations() {
        auto next = firstStation();
        for (auto &workstation : _workstations) {
            workstation = next;
            next = const_cast<Workstation *>(next->getNextStation());
        }
    }

    bool LineManager::run(std::ostream &os) {
        os << "Line Manager Iteration: " << ++_iteration << std::endl;
        if (!pending.empty()) {
            *_firstStation += std::move(pending.front());
            pending.pop_front();
        }
        std::for_each(_workstations.begin(), _workstations.end(), [&](Workstation *station) {
            station->fill(os);
        });
        std::for_each(_workstations.begin(), _workstations.end(), [&](Workstation *station) {
            station->attemptToMoveOrder();
        });
        return _orderNo == (completed.size() + incomplete.size());
    }

    void LineManager::display(std::ostream &os) const {
        std::for_each(_workstations.begin(), _workstations.end(), [&](const Workstation *workstation) {
            workstation->display(os);
        });
    }

    const auto push = [](std::unordered_map<std::string, int> &hashmap, const std::string &key) {
        const auto &record = hashmap.find(key);
        if (record == hashmap.end())
            hashmap.insert(std::make_pair(key, 0));
        else record->second = 1;
    };

    Workstation *LineManager::firstStation() const {
        Workstation *result = nullptr;
        std::unordered_map<std::string, int> hashmap;
        for (const auto &workstation : _workstations) {
            push(hashmap, workstation->getItemName());
            if (workstation->getNextStation() != nullptr)
                push(hashmap, workstation->getNextStation()->getItemName());
        }
        for (const auto &each : hashmap) {
            if (!each.second) {
                std::for_each(_workstations.begin(), _workstations.end(), [&](Workstation *workstation) {
                    if (workstation->getItemName() == each.first) result = workstation;
                });
            }
        }
        return result;
    }
}
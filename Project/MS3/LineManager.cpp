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
        for (auto &station : stations) {
            station->setNextStation(nullptr);
        }
        if (configFile.is_open()) {
            std::string buffer;
            while (configFile.good()) {
                std::getline(configFile, buffer);
                size_t position = 0;
                bool more = true;
                std::string token = util.extractToken(buffer, position, more);
                for (auto &station : stations) {
                    if (station->getItemName() == token)
                        _workstations.push_back(station);
                }
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
        std::vector<Workstation *> _linkedStation;
        auto nextStation = firstStation();
        do {
            _linkedStation.emplace_back(nextStation);
            if (nextStation != nullptr) nextStation = const_cast<Workstation *>(nextStation->getNextStation());
        } while (nextStation != nullptr);
        _workstations = std::move(_linkedStation);
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

    Workstation *LineManager::firstStation() const {
        Workstation *result = nullptr;
        std::for_each(_workstations.begin(), _workstations.end(), [&](Workstation *workstation) {
            if (!isNextStation(workstation))
                result = workstation;
        });
        return result;
    }

    bool LineManager::isNextStation(const Workstation *workstation) const {
        bool result = false;
        std::for_each(_workstations.begin(), _workstations.end(), [&](Workstation *station) {
            if (station->getNextStation() == workstation)
                result = true;
        });
        return result;
    }
}
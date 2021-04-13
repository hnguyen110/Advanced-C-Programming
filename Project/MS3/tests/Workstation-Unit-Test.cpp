#include <iostream>
#include "catch.hpp"
#include "../Utilities.h"
#include "../Workstation.h"

using namespace sdds;

TEST_CASE("Workstation", "[workstation-constructor]") {
    SECTION("Workstation constructor") {
        Utilities::setDelimiter(',');
        Workstation workstation("CPU,123456,5,Central Processing Unit");
        REQUIRE(workstation.getItemName() == "CPU");
        REQUIRE(workstation.getNextSerialNumber() == 123456);
        REQUIRE(workstation.getQuantity() == 5);
        workstation.updateQuantity();
        REQUIRE(workstation.getQuantity() == 4);
        workstation.updateQuantity();
        workstation.updateQuantity();
        workstation.updateQuantity();
        workstation.updateQuantity();
        workstation.updateQuantity();
        REQUIRE(workstation.getQuantity() == 0);
        REQUIRE(workstation.getNextStation() == nullptr);
        REQUIRE(workstation.isOrdersEmpty());
    }

    SECTION("Workstation add operator", "[workstation-add-operator]") {
        Utilities::setDelimiter(',');
        Workstation workstation("CPU,123456,5,Central Processing Unit");
        Utilities::setDelimiter('|');
        CustomerOrder order("Chris S.|Laptop|CPU");
        workstation += std::move(order);
        REQUIRE(workstation.retrieveOrdersSize() == 1);
    }

    SECTION("Workstation fill function", "[workstation-fill]") {
        Utilities::setDelimiter(',');
        Workstation workstation("CPU,123456,5,Central Processing Unit");
        workstation.fill(std::cout);
        REQUIRE(workstation.getQuantity() == 5);
        Utilities::setDelimiter('|');
        CustomerOrder order("Chris S.|Laptop|CPU");
        workstation += std::move(order);
        workstation.fill(std::cout);
        REQUIRE(workstation.isItemFilled(workstation.getItemName()) == true);
        REQUIRE(workstation.isFilled() == true);
        REQUIRE(workstation.getQuantity() == 4);
    }

    SECTION("Workstation setNextStation function,", "[workstation-next-station]") {
        Utilities::setDelimiter(',');
        Workstation firstStation("CPU,123456,5,Central Processing Unit");
        Workstation secondStation("GPU,56789,7,Graphic Processing Unit");
        REQUIRE(firstStation.getNextStation() == nullptr);
        REQUIRE(secondStation.getNextStation() == nullptr);
        firstStation.setNextStation(&secondStation);
        REQUIRE(firstStation.getNextStation() == &secondStation);
        firstStation.setNextStation(nullptr);
        REQUIRE(firstStation.getNextStation() == nullptr);
        secondStation.setNextStation(&firstStation);
        REQUIRE(secondStation.getNextStation() == &firstStation);
        secondStation.setNextStation(nullptr);
        REQUIRE(secondStation.getNextStation() == nullptr);
    }

    SECTION("Workstation attemptToMoveOrder function", "[workstation-move-station]") {
        Utilities::setDelimiter(',');
        Workstation firstStation("CPU,123456,5,Central Processing Unit");
        Workstation secondStation("GPU,56789,7,Graphic Processing Unit");
        Utilities::setDelimiter('|');
        CustomerOrder order("Chris S.|Laptop|CPU|GPU");
        firstStation.setNextStation(&secondStation);
        REQUIRE(firstStation.isOrdersEmpty());
        REQUIRE(secondStation.isOrdersEmpty());
        firstStation += std::move(order);
        REQUIRE(firstStation.retrieveOrdersSize() == 1);
        REQUIRE(secondStation.isOrdersEmpty());
        REQUIRE(firstStation.attemptToMoveOrder() == false);
        firstStation.fill(std::cout);
        REQUIRE(firstStation.attemptToMoveOrder() == true);
        REQUIRE(firstStation.isOrdersEmpty());
        REQUIRE(secondStation.retrieveOrdersSize() == 1);
        REQUIRE(secondStation.attemptToMoveOrder() == false);
        secondStation.fill(std::cout);
        REQUIRE(secondStation.attemptToMoveOrder() == true);
    }
}
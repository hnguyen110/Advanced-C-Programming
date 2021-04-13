cmake_minimum_required(VERSION 3.17)
project(MS3)

set(CMAKE_CXX_STANDARD 17)

add_executable(MS3 main.cpp Workstation.cpp Workstation.h LineManager.cpp LineManager.h Station.cpp Station.h Utilities.cpp Utilities.h CustomerOrder.cpp CustomerOrder.h)

#add_executable(MS3 tests/test_main.cpp tests/catch.hpp tests/Workstation-Unit-Test.cpp Workstation.cpp Workstation.h LineManager.cpp LineManager.h Station.cpp Station.h Utilities.cpp Utilities.h CustomerOrder.cpp CustomerOrder.h tests/Workstation-Unit-Test.cpp tests/test_main.cpp)
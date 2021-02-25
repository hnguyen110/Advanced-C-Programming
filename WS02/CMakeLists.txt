cmake_minimum_required(VERSION 3.17)
project(WS02)

set(CMAKE_CXX_STANDARD 17)
#add_subdirectory(lib/googletest)
#include_directories(lib/googletest/googletest/include)
#include_directories(lib/googletest/googlemock/include)
add_executable(WS02 w2_p2.cpp TimedEvents.h TimedEvents.cpp StringSet.h StringSet.cpp)
#target_link_libraries(WS02 gtest gtest_main)
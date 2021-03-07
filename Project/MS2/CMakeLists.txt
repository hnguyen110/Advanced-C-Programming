cmake_minimum_required(VERSION 3.17)
project(MS2)

set(CMAKE_CXX_STANDARD 17)

add_executable(MS2 main.cpp CustomerOrder.cpp CustomerOrder.h Station.cpp Station.h Utilities.cpp Utilities.h)
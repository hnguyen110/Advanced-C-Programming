cmake_minimum_required(VERSION 3.17)
project(Debug)

set(CMAKE_CXX_STANDARD 17)

add_executable(Debug main.cpp Foo.cpp Foo.h Test.cpp Test.h)
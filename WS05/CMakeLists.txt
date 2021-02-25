cmake_minimum_required(VERSION 3.17)
project(WS05)

set(CMAKE_CXX_STANDARD 17)

add_executable(WS05 main.cpp Book.cpp Book.h SpellChecker.cpp SpellChecker.h Movie.cpp Movie.h Collection.h Utils.h)
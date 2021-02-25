cmake_minimum_required(VERSION 3.17)
project(WS04)

set(CMAKE_CXX_STANDARD 17)

add_executable(WS04 main.cpp Reservation.cpp Reservation.h Restaurant.cpp Restaurant.h ConfirmationSender.cpp ConfirmationSender.h)
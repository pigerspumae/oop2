cmake_minimum_required(VERSION 3.13)
project(football_ch)

set(CMAKE_CXX_STANDARD 17)

add_executable(football_ch main.cpp members_of_championship.cpp members_of_championship.hpp championship.cpp championship.hpp)
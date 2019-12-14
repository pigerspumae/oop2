cmake_minimum_required(VERSION 3.13)
project(qusort)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp qusort.hpp)
add_executable(qusort ${SOURCE_FILES})
add_library(mylib ${SOURCE_FILES})

add_subdirectory(g_test/googletest)
include_directories(g_test/googletest/)

add_executable(t_qusort g_test/test.cpp g_test/test.h)
target_link_libraries(t_qusort gtest gtest_main)
target_link_libraries(t_qusort gmock gmock_main)
target_link_libraries(t_qusort mylib)
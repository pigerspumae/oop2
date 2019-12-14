cmake_minimum_required(VERSION 3.13)
project(my_shared_ptr)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp my_shared_ptr.hpp)
add_executable(my_shared_ptr ${SOURCE_FILES})

add_library(mylib ${SOURCE_FILES})
add_subdirectory(g_test/googletest)
include_directories(g_test/googletest/)

add_executable(t_ptr g_test/test.cpp g_test/test.h my_shared_ptr.hpp)
target_link_libraries(t_ptr gtest gtest_main)
target_link_libraries(t_ptr gmock gmock_main)
target_link_libraries(t_ptr mylib)
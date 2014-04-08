cmake_minimum_required (VERSION 2.6)

project (TSP)

add_definitions(-std=c99 -O2)
#option de gcc

set (CMAKE_INSTALL_PREFIX .)


enable_testing()

include_directories(include)
add_subdirectory (src)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
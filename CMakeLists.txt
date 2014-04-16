cmake_minimum_required (VERSION 2.6)

project (TSP C)

add_definitions(-std=c99 -g)
#option de gcc

set (CMAKE_INSTALL_PREFIX .)
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

enable_testing()

include_directories(include)
add_subdirectory (src)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
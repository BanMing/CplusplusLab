cmake_minimum_required(VERSION 3.15.3)
project(CplusplusLabe)

set(CMAKE_CXX_STANDARD 11)

add_executable(CplusplusLabe main.cpp)

add_subdirectory(concurrency)
add_subdirectory(math_test)

target_link_libraries(CplusplusLabe PUBLIC math_test)
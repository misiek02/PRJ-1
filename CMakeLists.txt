cmake_minimum_required(VERSION 3.22)
project(PRJ_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PRJ_1
        src/main.cpp)
target_link_libraries(PRJ_1 sfml-audio sfml-graphics sfml-window sfml-system)

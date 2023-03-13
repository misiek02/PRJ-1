cmake_minimum_required(VERSION 3.22)
project(PRJ_1)

set(CMAKE_CXX_STANDARD 17)



add_executable(PRJ_1
        src/main.cpp)
target_link_libraries(PRJ_1 sfml-audio sfml-graphics sfml-window sfml-system)
target_include_directories(PRJ_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


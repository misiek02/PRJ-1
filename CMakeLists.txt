cmake_minimum_required(VERSION 3.22)
project(PRJ_1)

set(CMAKE_CXX_STANDARD 17)



add_executable(PRJ_1
        src/main.cpp inc/list.h inc/stackTab.h inc/queueTab.h inc/Array.h inc/stackList.h inc/catch.hpp inc/singly_linked_list.h inc/weight.h inc/EdgeList.h inc/Dijkstry.h)
target_link_libraries(PRJ_1 sfml-audio sfml-graphics sfml-window sfml-system)
target_include_directories(PRJ_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_executable(tests
src/tests.cpp inc/list.h inc/stackTab.h inc/queueTab.h inc/Array.h inc/stackList.h)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

include(CPack)

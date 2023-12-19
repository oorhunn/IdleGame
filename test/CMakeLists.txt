cmake_minimum_required(VERSION 3.14)
set(This IdlegameTests)

project(${This} VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

set(Sources
    WorstSearchAlgorithmsTest.cpp
    WorstBasicDataStructuresTest.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    worstAlgorithms
)




add_test(
    NAME ${This}
    COMMAND ${This}
)

cmake_minimum_required(VERSION 3.14)
set(This Idlegame)

project(${This} C CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/eigen-3.x.x)


enable_testing()

add_subdirectory(googletest)

add_subdirectory(DataStructuresAndAlgorithmsStudy)
add_subdirectory(CircuitSim)
add_subdirectory(EigenStuff)

add_subdirectory(test)

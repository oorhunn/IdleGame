cmake_minimum_required(VERSION 3.0.0)
project(IdleGame VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CTest)
enable_testing()

add_executable(IdleGame main.cpp player/Player.cpp player/User.cpp math_utils/WorstMatrix.cpp)

target_include_directories(IdleGame PRIVATE ${WORKING_DIRECTORY}/player ${WORKING_DIRECTORY}/math_utils)

include(CPack)

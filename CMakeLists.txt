cmake_minimum_required(VERSION 3.0.0)
project(IdleGame VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CTest)
enable_testing()

add_executable(IdleGame main.cpp player/PlayerBase.cpp player/User.cpp math_utils/WorstMathUtils.cpp player/Monster.cpp weapon/weapon_base.cpp)

target_include_directories(IdleGame PRIVATE ${WORKING_DIRECTORY}/player ${WORKING_DIRECTORY}/math_utils ${WORKING_DIRECTORY}/weapon)

include(CPack)

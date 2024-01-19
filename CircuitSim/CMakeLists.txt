
set(This CircuitSim)
project(${This} CXX C)
set(Sources
    main.cpp
    src/Components.cpp
    src/Circuit.cpp
    src/AdjacentList.cpp
    src/CircuitResolver.cpp
    src/ComponentHashMapObserver.cpp
    src/CircuitPaths.cpp

)

add_library(${This} STATIC ${Sources})

target_include_directories(${This} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${This}instance ${Sources})

target_link_libraries(${This}instance PRIVATE ${This})

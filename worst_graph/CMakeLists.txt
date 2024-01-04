

set (This worstGraph)
project(${This} CXX C)

set (Sources 
    main.cpp
    src/Graph.cpp
)

add_library(${This} STATIC ${Sources})

target_include_directories(${This}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(${This}instance ${Sources})

target_link_libraries(${This}instance PRIVATE ${This})
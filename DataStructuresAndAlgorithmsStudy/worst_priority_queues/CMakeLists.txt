set(This worstPriorityQueues)
project(${This} CXX C)

set(LibSources
    src/BinaryHeap.cpp
)

add_library(${This}Lib STATIC ${LibSources})

target_include_directories(${This}Lib 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(AppSources
    main.cpp
)

add_executable(${This} ${AppSources})

target_link_libraries(${This} PRIVATE ${This}Lib)

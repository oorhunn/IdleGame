set(This DesignPatterns)
project(${This} CXX C)

set(Sources
    main.cpp
    src/CompositePattern/Composite.cpp
    src/StrategyPattern/Strategy.cpp

)

add_library(${This} STATIC ${Sources})


target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/CompositePattern/)
target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/StrategyPattern/)

# target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/CompositePattern/)


add_executable(${This}instance ${Sources})



target_link_libraries(${This}instance PRIVATE ${This})

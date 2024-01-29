set(This EigenStuff)
project(${This} CXX C)

# Find OpenMP

# Set source files
set(Sources
    main.cpp
)

# Create a library from the sources
add_library(${This} STATIC ${Sources})

# Include the Eigen library
target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../eigen-3.4.0)

# Assuming your 'include' directory is in the EigenStuff directory
target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Enable OpenMP if found
# if(OpenMP_CXX_FOUND)
#     target_link_libraries(${This} PUBLIC OpenMP::OpenMP_CXX)
#     target_compile_options(${This} PRIVATE -fopenmp)  # Adjust for your compiler if needed
# endif()

# Create an executable
add_executable(${This}instance ${Sources})

# Link against Eigen and OpenMP
# target_link_libraries(${This}instance PRIVATE ${This})
find_package(OpenMP)

target_link_libraries(${This}instance PRIVATE ${This} OpenMP::OpenMP_CXX)

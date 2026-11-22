cmake_minimum_required(VERSION 3.20)

project(NBodyProblem
    VERSION 1.0
    LANGUAGES CXX
)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find SFML
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

# Source files
set(SOURCES
    src/Cluster.cpp
    src/Coords.cpp
    src/Example.cpp
    src/main.cpp
    src/Star.cpp
    src/Utiles.cpp
)

# Create executable
add_executable(NBodyProblem ${SOURCES})

# Include directories
target_include_directories(NBodyProblem PRIVATE include)

# Link libraries
target_link_libraries(NBodyProblem PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

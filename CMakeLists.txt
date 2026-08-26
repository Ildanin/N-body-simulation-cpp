cmake_minimum_required(VERSION 3.24)

project(NBody LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_STATIC_LIBRARIES ON)

find_package(SFML 3.1 COMPONENTS Graphics REQUIRED)

add_executable(NBody #WIN32
    src/main.cpp
    src/Star.cpp
    src/Cluster.cpp
    src/Coords.cpp
    src/Utiles.cpp
    src/Example.cpp)

add_custom_command(TARGET NBody POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:NBody>/assets
)

target_include_directories(NBody PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(NBody PRIVATE SFML::Graphics)

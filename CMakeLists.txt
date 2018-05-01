cmake_minimum_required(VERSION 3.10)
project(StarFighter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")
set(EXECUTABLE_NAME "StarFighter")

add_library(application headers/Application.h src/Application.cpp)
add_library(gameobject headers/GameObject.h src/GameObject.cpp)
add_executable(${EXECUTABLE_NAME} src/main.cpp)

# Detect and add SFML
set(CMAKE_MODULE_PATH "./cmake-build-debug")
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

target_link_libraries(StarFighter.out application gameobject)
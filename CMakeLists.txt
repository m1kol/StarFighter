cmake_minimum_required(VERSION 3.10)
project(StarFighter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_library(application headers/Application.h src/Application.cpp)
add_library(gameobject headers/GameObject.h src/GameObject.cpp)
add_executable(StarFighter.out src/main.cpp)

target_link_libraries(StarFighter.out application gameobject)
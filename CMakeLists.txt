cmake_minimum_required(VERSION 3.10)
project(StarFighter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall")

add_library(application Application.h Application.cpp)
add_library(gameobject GameObject.h GameObject.cpp)
add_executable(StarFighter.out main.cpp)

target_link_libraries(StarFighter.out application gameobject)
cmake_minimum_required(VERSION 3.10)
project(StarFighter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall -lsfml-graphics -lsfml-window -lsfml-system")

add_executable(StarFighter.out
        Application.cpp
        Application.h
        GameObject.cpp
        GameObject.h
        main.cpp
        )
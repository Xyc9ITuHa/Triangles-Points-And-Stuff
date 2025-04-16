cmake_minimum_required(VERSION 3.30)
project(second)

set(CMAKE_CXX_STANDARD 20)

add_executable(second main.cpp
        triangle.cpp
        triangle.h)

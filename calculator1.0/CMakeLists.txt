cmake_minimum_required(VERSION 3.12)
project(calculator1_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(calculator1_0
        button.cpp
        button.h
        calculator.cpp
        calculator.h
        main.cpp)

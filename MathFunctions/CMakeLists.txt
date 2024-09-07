cmake_minimum_required(VERSION 3.29)
project(MathFunctions C)

set(CMAKE_C_STANDARD 99)

add_executable(MathFunctions main.c
        mathTools.c
        mathTools.h)

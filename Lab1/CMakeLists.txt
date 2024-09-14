cmake_minimum_required(VERSION 3.29)
project(Lab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab1 main.c
        schoolResults.c
        schoolResults.h
        randomGenerator.c
        randomGenerator.h
        minMax.c
        minMax.h)

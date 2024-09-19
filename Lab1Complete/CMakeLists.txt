cmake_minimum_required(VERSION 3.29)
project(Lab1Complete C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab1Complete main.c
        minMax.c
        minMax.h
        randomGenerator.c
        randomGenerator.h
        schoolResults.c
        schoolResults.h
        guess.c
        guess.h
)

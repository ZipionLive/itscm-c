cmake_minimum_required(VERSION 3.29)
project(Lab6 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab6 main.c
        credentials.c
        credentials.h
        stringTools.c
        stringTools.h
        fileHandling.c
        fileHandling.h
        userInput.c
        userInput.h)

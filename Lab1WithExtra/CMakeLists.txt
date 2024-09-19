cmake_minimum_required(VERSION 3.29)
project(Lab1WithExtra C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab1WithExtra main.c
        copyTab.c
        copyTab.h
        guess.c
        guess.h
        minMax.c
        minMax.h
        order.c
        order.h
        randomGenerator.c
        randomGenerator.h
        schoolResults.c
        schoolResults.h
        tabSwitch.c
        tabSwitch.h)

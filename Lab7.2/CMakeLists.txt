cmake_minimum_required(VERSION 3.29)
project(Lab7_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab7_2 main.c
        student.c
        student.h
        class.c
        class.h
        lesson.c
        lesson.h
        userInput.c
        stringTools.c
)

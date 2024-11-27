cmake_minimum_required(VERSION 3.29)
project(Lab7 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab7 main.c
        person.c
        person.h
        userInput.c
        stringTools.c
        rectangle.c
        rectangle.h
        date.c
        date.h
        event.c
        event.h
        mathTools.c
        mathTools.h
        student.c
        student.h)

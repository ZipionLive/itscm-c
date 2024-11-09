cmake_minimum_required(VERSION 3.29)
project(FileHandling C)

set(CMAKE_C_STANDARD 11)

add_executable(FileHandling main.c
        fileHandling.c
        fileHandling.h)

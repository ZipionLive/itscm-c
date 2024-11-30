cmake_minimum_required(VERSION 3.29)
project(ChainList C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ChainList
    data.c
    data.h
    dataList.c
    dataList.h
    dataNode.c
    dataNode.h
    main.c
    stringTools.c
    stringTools.h
    userInput.c
    userInput.h)

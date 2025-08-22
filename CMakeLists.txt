cmake_minimum_required(VERSION 3.22.1)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled1 main.cpp
        Item.h
        Item.cpp
        Time.h
        Month.h
        Month.cpp
        Year.h
        Year.cpp
        User.h
        User.cpp)

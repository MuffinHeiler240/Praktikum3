cmake_minimum_required(VERSION 3.29)
project(Praktikum3 C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_COMPILE_WARNING_AS_ERROR true)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -pedantic-errors -Wall -Wextra -Werror")

add_executable(Praktikum3 main.c
        root.h
        root.c
)

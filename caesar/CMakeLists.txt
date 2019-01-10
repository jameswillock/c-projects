cmake_minimum_required(VERSION 3.9)
project(caesar C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-lcs50")

add_executable(caesar main.c)
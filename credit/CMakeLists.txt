cmake_minimum_required(VERSION 3.10)
project(credit C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-lcs50")

add_executable(credit main.c)
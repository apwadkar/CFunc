cmake_minimum_required(VERSION 3.12)
project(CFunc C)

set(CMAKE_C_STANDARD 11)

set(C_SOURCES main.c array.c list.c functional.c)

add_executable(${PROJECT_NAME} ${C_SOURCES})

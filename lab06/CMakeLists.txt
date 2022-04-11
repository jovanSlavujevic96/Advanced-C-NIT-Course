cmake_minimum_required(VERSION 3.16)
project(lab06 C)

add_compile_options("-ggdb3")

add_library(CircularBuffer STATIC task1/circular_buffer.c)

add_executable(task1 task1/main.c)
target_link_libraries(task1 PRIVATE CircularBuffer)

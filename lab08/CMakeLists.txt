cmake_minimum_required(VERSION 3.16)
project(lab06 C)

add_compile_options("-ggdb3")

add_library(Stack STATIC stack.c)

add_executable(final main.c)
target_link_libraries(final PRIVATE Stack)

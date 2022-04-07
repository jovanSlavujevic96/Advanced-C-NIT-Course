cmake_minimum_required(VERSION 3.16)
project(lab04 C)

add_compile_options("-ggdb3")

add_executable(task1 task1/program.c)

add_executable(task2 task2/bmp.c task2/e_bitmap.c task2/imageProcessing.c)

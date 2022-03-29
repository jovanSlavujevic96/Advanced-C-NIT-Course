project(lab01)

set(CMAKE_C_FLAGS "-Wall -ggdb3")

add_executable(example1 ${CMAKE_CURRENT_SOURCE_DIR}/example1/example1.c)

add_executable(example2 ${CMAKE_CURRENT_SOURCE_DIR}/example2/example2.c)

add_executable(example3 ${CMAKE_CURRENT_SOURCE_DIR}/example3/example3.c)

add_executable(program  ${CMAKE_CURRENT_SOURCE_DIR}/task1/program.c)

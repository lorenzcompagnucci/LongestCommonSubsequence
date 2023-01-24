cmake_minimum_required(VERSION 3.19)
project(LCS)

set(CMAKE_C_STANDARD 99)

add_executable(LCS main.c mem_utils.c mem_utils.h file.c file.h solver.c solver.h)
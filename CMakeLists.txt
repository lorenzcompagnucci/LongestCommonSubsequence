cmake_minimum_required(VERSION 3.19)
project(LCS)

set(CMAKE_CXX_STANDARD 14)

add_executable(LCS main.c mem_utils.c mem_utils.h file.c file.h solver.c solver.h)
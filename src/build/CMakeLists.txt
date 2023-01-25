cmake_minimum_required(VERSION 3.19)
project(LCS)

set(CMAKE_C_STANDARD 99)

add_executable(LCS main.c memory/mem_utils.c memory/mem_utils.h file/file.c file/file.h solver/solver.c solver/solver.h)
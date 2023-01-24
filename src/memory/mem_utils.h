#ifndef LCS_MEM_UTILS_H
#define LCS_MEM_UTILS_H

#define MATRIX_ERR "ERROR WHILE ALLOCATING MEMORY FOR A MATRIX"
#define MATRIX_ROW_ERR "ERROR WHILE ALLOCATING MEMORY FOR A ROW"

#include "../solver/solver.h"

char* Memory_createString(int length, char* error);
void Memory_freeString(char* string);
void Memory_checkString(char* string, char* errmessage);
char** Memory_createMatrix(int rows, int columns);
void Memory_freeMatrixes(char** char_matrix, int** int_matrix, int rows);
void Memory_checkCharMatrix(char** matrix, char* errmessage);
void Memory_freeSolver(Solver_Solver_t* s);

#endif //LCS_MEM_UTILS_H
#ifndef LCS_MEM_UTILS_H
#define LCS_MEM_UTILS_H

#define MATRIX_ERR "ERROR WHILE ALLOCATING MEMORY FOR A MATRIX"
#define MATRIX_ROW_ERR "ERROR WHILE ALLOCATING MEMORY FOR A ROW"

#include "solver.h"

char* create_string(int length, char* error);
void free_string(char* string);
void check_string(char* string, char* errmessage);
char** create_char_matrix(int rows, int columns);
int** create_int_matrix(int rows, int columns);
void free_matrixes(char** char_matrix, int** int_matrix, int rows);
void check_char_matrix(char** matrix, char* errmessage);
void check_int_matrix(int** matrix, char* errmessage);
void free_solver(solver* s);

#endif //LCS_MEM_UTILS_H
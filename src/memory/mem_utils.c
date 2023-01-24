#include <stdio.h>
#include <stdlib.h>

#include "mem_utils.h"

char* Memory_createString(int length, char* error) {
    char* buffer = (char*) malloc(sizeof(char) * length);
    Memory_checkString(buffer, error);
    return buffer;
}

void Memory_freeString(char* string) {
    if (string != NULL) {
        free(string);
        string = NULL;
    }
}

void Memory_checkString(char* string, char* errmessage) {
    if (string == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

char** Memory_createMatrix(int rows, int columns) {
    char** matrix = (char**) malloc(sizeof(char*) * rows);
    Memory_checkCharMatrix(matrix, MATRIX_ERR);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*) calloc(columns, sizeof(char*));
        Memory_checkString(matrix[i], MATRIX_ROW_ERR);
    }
    return matrix;
}

void Memory_freeMatrixes(char** char_matrix, int** int_matrix, int rows) {
    if (char_matrix != NULL && int_matrix != NULL) {
        for (int i = 0; i < rows; i++) {
            Memory_freeString(char_matrix[i]);
            free(int_matrix[i]);
        }
        free(char_matrix);
        free(int_matrix);
        char_matrix = NULL;
        int_matrix = NULL;
    }
}

void Memory_checkCharMatrix(char** matrix, char* errmessage) {
    if (matrix == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

void Memory_freeSolver(Solver_Solver_t* s) {
    Memory_freeString(s->first_string);
    Memory_freeString(s->second_string);
    Memory_freeMatrixes(s->instructions, s->values, s->rows);
    Memory_freeString(s->solution);
    free(s);
}
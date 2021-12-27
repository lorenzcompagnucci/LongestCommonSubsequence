#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mem_utils.h"

char* create_string(int length, char* error) {
    char* buffer = (char*) malloc(sizeof(char) * length);
    check_string(buffer, error);
    return buffer;
}

void free_string(char* string) {
    if (string != NULL) {
        free(string);
        string = NULL;
    }
}

void check_string(char* string, char* errmessage) {
    if (string == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

char** create_char_matrix(int rows, int columns) {
    char** matrix = (char**) malloc(sizeof(char*) * rows);
    check_char_matrix(matrix, MATRIX_ERR);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*) calloc(columns, sizeof(char*));
        check_string(matrix[i], MATRIX_ROW_ERR);
    }
    return matrix;
}

int** create_int_matrix(int rows, int columns) {
    int** matrix = (int**) malloc(sizeof(int*) * rows);
    check_int_matrix(matrix, MATRIX_ERR);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) calloc(columns, sizeof(int*));
    }
    return matrix;
}

void free_matrixes(char** char_matrix, int** int_matrix, int rows) {
    if (char_matrix != NULL && int_matrix != NULL) {
        for (int i = 0; i < rows; i++) {
            free_string(char_matrix[i]);
            free(int_matrix[i]);
        }
        free(char_matrix);
        free(int_matrix);
        char_matrix = NULL;
        int_matrix = NULL;
    }
}

void check_char_matrix(char** matrix, char* errmessage) {
    if (matrix == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

void check_int_matrix(int** matrix, char* errmessage) {
    if (matrix == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

void free_solver(solver* s) {
    free_string(s->first_string);
    free_string(s->second_string);
    free_matrixes(s->instructions, s->values, s->rows);
    free_string(s->solution);
    free(s);
}
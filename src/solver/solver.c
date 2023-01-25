#include <stdlib.h>
#include <string.h>

#include "solver.h"
#include "../file/file.h"
#include "../memory/mem_utils.h"

Solver_Solver_t* createSolver(char* first_path, char* second_path) {
    Solver_Solver_t* s = (Solver_Solver_t*) malloc(sizeof(Solver_Solver_t));
    s->first_string = File_readFile(first_path);
    s->second_string = File_readFile(second_path);
    s->rows = (int) strlen(s->first_string) + 1;
    s->columns = (int) strlen(s->second_string) + 1;
    s->values = (int**) Memory_createMatrix(s->rows, s->columns);
    s->instructions = Memory_createMatrix(s->rows, s->columns);
    return s;
}

static int getMax(int n1, int n2) {
    return (n1 >= n2) ? n1 : n2;
}

void fillMatrixes(Solver_Solver_t* s) {
    for (int i = 1; i < s->rows; i++) {
        for (int j = 1; j < s->columns; j++) {
            if (s->first_string[i-1] == s->second_string[j-1]) {
                s->values[i][j] = s->values[i-1][j-1] + 1;
                s->instructions[i][j] = 'd';
            } else {
                s->values[i][j] = getMax(s->values[i-1][j], s->values[i][j-1]);
                if (s->values[i-1][j] >= s->values[i][j-1]) {
                    s->instructions[i][j] = 't';
                } else {
                    s->instructions[i][j] = 'l';
                }
            }
        }
    }
}

void createSolution(Solver_Solver_t* s) {
    int m = s->rows - 1;
    int n = s->columns - 1;
    int i = s->values[m][n];
    s->solution = Memory_createString(i+1, SOLUTION_ERROR);
    s->solution[i] = '\0';
    while (s->instructions[m][n] != 0) {
        if (s->instructions[m][n] == 'd') {
            s->solution[i-1] = s->first_string[m-1];
            i--;
            m--;
            n--;
        } else if (s->instructions[m][n] == 'l') {
            n--;
        } else if (s->instructions[m][n] == 't') {
            m--;
        }
    }
}

int Solver_printSolution(char* first_path, char* second_path, char* output_path) {
    Solver_Solver_t* s = createSolver(first_path, second_path);
    if ((s->rows-1) == 0 || (s->columns-1) == 0) {
        File_printOnFile(output_path, "");
    } else if (strcmp(s->first_string, s->second_string) == 0) {
        File_printOnFile(output_path, s->first_string);
    } else {
        fillMatrixes(s);
        createSolution(s);
        File_printOnFile(output_path, s->solution);
    }
    Memory_freeSolver(s);
    return 1;
}
#ifndef LCS_SOLVER_H
#define LCS_SOLVER_H

#define SOLUTION_ERROR "ERROR WHILE ALLOCATING MEMORY FOR THE SOLUTION"

typedef struct _Solver_Solver_t {
    char* first_string;
    char* second_string;
    int rows;
    int columns;
    int** values;
    char** instructions;
    char* solution;
} Solver_Solver_t;

int Solver_printSolution(char* first_path, char* second_path, char* output_path);

#endif //LCS_SOLVER_H
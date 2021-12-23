#ifndef LCS_SOLVER_H
#define LCS_SOLVER_H

#define SOLUTION_ERROR "ERROR WHILE ALLOCATING MEMORY FOR THE SOLUTION"

typedef struct solver {
    char* first_string;
    char* second_string;
    int rows;
    int columns;
    int** values;
    char** instructions;
    char* solution;
} solver;

int print_solution(char* first_path, char* second_path, char* output_path);
solver* create_solver(char* first_path, char* second_path);
void fill_matrixes(solver* s);
void create_solution(solver* s);
int get_max(int n1, int n2);

#endif //LCS_SOLVER_H
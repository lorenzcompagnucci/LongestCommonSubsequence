#include <stdlib.h>
#include <string.h>

#include "solver.h"
#include "file.h"
#include "mem_utils.h"

int solve(char* first_path, char* second_path, char* output_path) {
    solver* s = get_solver(first_path, second_path);
    if ((s->rows-1) == 0 || (s->columns) == 0) {
        print_on_file(output_path, "");
    } else if (strcmp(s->first_string, s->second_string) == 0) {
        print_on_file(output_path, s->first_string);
    } else {
        fill_matrixes(s);
        create_solution(s);
        print_on_file(output_path, s->solution);
    }
    free_solver(s);
    return 1;
}

solver* get_solver(char* first_path, char* second_path) {
    solver* s = (solver*) malloc(sizeof(solver));
    s->first_string = read_file(first_path);
    s->second_string = read_file(second_path);
    s->rows = strlen(s->first_string) + 1;
    s->columns = strlen(s->second_string) + 1;
    s->values = create_int_matrix(s->rows, s->columns);
    s->instructions = create_char_matrix(s->rows, s->columns);
    return s;
}

void fill_matrixes(solver* s) {
    for (int i = 1; i < s->rows; i++) {
        for (int j = 1; j < s->columns; j++) {
            if (s->first_string[i-1] == s->second_string[j-1]) {
                s->values[i][j] = s->values[i-1][j-1] + 1;
                s->instructions[i][j] = 'd';
            } else {
                s->values[i][j] = get_max(s->values[i-1][j], s->values[i][j-1]);
                if (s->values[i-1][j] >= s->values[i][j-1]) {
                    s->instructions[i][j] = 't';
                } else {
                    s->instructions[i][j] = 'l';
                }
            }
        }
    }
}

void create_solution(solver* s) {
    int m = s->rows - 1;
    int n = s->columns - 1;
    char seq = s->instructions[m][n];
    int i = s->values[m][n];
    s->solution = create_string(i+1, SOLUTION_ERROR);
    s->solution[i] = '\0';
    while (seq != 0) {
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
        seq = s->instructions[m][n];
    }
}

int get_max(int n1, int n2) {
    if (n1 >= n2) {
        return n1;
    }
    return n2;
}
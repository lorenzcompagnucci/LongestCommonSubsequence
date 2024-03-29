#include <stdio.h>

#include "solver/solver.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("There must be 4 args, but %d were given.\n", argc);
        printf("LCS first_string_path second_string_path output_path\n");
        return 0;
    }
    return Solver_printSolution(argv[1], argv[2], argv[3]);
}
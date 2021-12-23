#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "file.h"
#include "mem_utils.h"

char* read_file(char* input_file) {
    FILE* fin = fopen(input_file, "r");
    check_file(fin, FIN_ERROR);
    char* buffer = reader(fin);
    fclose(fin);
    return buffer;
}

char* reader(FILE* fin) {
    char* buffer = create_string(file_size(fin)+1, INP_BUFF_ERROR);
    int i = 0;
    char c;
    while ((c = toupper(fgetc(fin))) != EOF) {
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    return buffer;
}

long int file_size(FILE* fp) {
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);
    return size;
}

void print_on_file(char* file, char* message) {
    FILE* fout = fopen(file, "w");
    check_file(fout, FOUT_ERROR);
    fprintf(fout, "%s", message);
    fclose(fout);
}

void check_file(FILE* fp, char* errmessage) {
    if (fp == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}
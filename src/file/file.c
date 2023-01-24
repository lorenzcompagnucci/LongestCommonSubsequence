#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "file.h"
#include "../memory/mem_utils.h"

static long int fileSize(FILE* fp) {
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);
    return size;
}

static char* reader(FILE* fin) {
    char* buffer = Memory_createString(file_size(fin)+1, INP_BUFF_ERROR);
    int i = 0;
    char c;
    while ((c = (char) toupper(fgetc(fin))) != EOF) {
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';
    return buffer;
}

static void checkFile(FILE* fp, char* errmessage) {
    if (fp == NULL) {
        printf("%s\n", errmessage);
        exit(0);
    }
}

char* File_readFile(char* input_file) {
    FILE* fin = fopen(input_file, "r");
    checkFile(fin, FIN_ERROR);
    char* buffer = reader(fin);
    fflush(fin);
    fclose(fin);
    return buffer;
}

void File_printOnFile(char* file, char* message) {
    FILE* fout = fopen(file, "w");
    checkFile(fout, FOUT_ERROR);
    fprintf(fout, "%s", message);
    fflush(fout);
    fclose(fout);
}
#ifndef LCS_FILE_H
#define LCS_FILE_H

#include <stdio.h>

#define FIN_ERROR "INPUT FILE ERROR"
#define FOUT_ERROR "OUTPUT FILE ERROR"
#define INP_BUFF_ERROR "INPUT FILE BUFFER ERROR"

char* read_file(char* input_file);
char* reader(FILE* fin);
long int file_size(FILE* fp);
void print_on_file(char* file, char* message);
void check_file(FILE* fp, char* errmessage);

#endif //LCS_FILE_H
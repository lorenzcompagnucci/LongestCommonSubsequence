#ifndef LCS_FILE_H
#define LCS_FILE_H

#include <stdio.h>

#define FIN_ERROR "INPUT FILE ERROR"
#define FOUT_ERROR "OUTPUT FILE ERROR"
#define INP_BUFF_ERROR "INPUT FILE BUFFER ERROR"

char* File_readFile(char* input_file);
void File_printOnFile(char* file, char* message);

#endif //LCS_FILE_H
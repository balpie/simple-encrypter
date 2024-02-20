//TODO
#ifndef ARGS_HANDLING
#define ARGS_HANDLING

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_FILENAME_LENGHT 30

int strToNumber(char* str);
char* generateNewName(const char* str);
char** getFileNames(long unsigned *numF);

#endif
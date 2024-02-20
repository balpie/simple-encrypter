#ifndef FILEHANDLING
#define FILEHANDLING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readFileContent(char* fileName, long unsigned *dim);
int writeFileContent(char* fileName, char *buffer, long unsigned len);


#endif

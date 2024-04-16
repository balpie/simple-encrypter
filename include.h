#ifndef INCLUDES
#define INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGHT 60
#define ENCRYPT 1
#define DECRYPT 0
#define NUM_BITS 8

int strToNumber(char* str);
char** getFileNames(long unsigned *numF);
void sumBasedEncryption(char* buff, unsigned long lenght, 
                        int key, int enc);
char* readFileContent(char* fileName, long unsigned *dim);
int writeFileContent(char* fileName, char *buffer, long unsigned len);

#endif

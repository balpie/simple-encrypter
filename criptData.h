#ifndef CRIPT_DATA
#define CRIPT_DATA

#define ENCRYPT 1
#define DECRYPT 0

#define NUM_BITS 8

char rotateLeft(char c, int d);
char rotateRight(char c, int d);
void sumBasedEncryption(char* buff, unsigned long lenght, int key, int enc);

#endif

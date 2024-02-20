#ifndef CRIPT_DATA
#define CRIPT_DATA

#define ENCRYPT 1
#define DECRYPT 0

#define LSB_1BYTE 1
#define MSB_1BYTE 0x80

char rotateLeft(char c);
char rotateRight(char c);
void sumBasedEncryption(char* buff, unsigned long lenght, int key, int enc);

#endif

#include "criptData.h"

char rotateLeft(char c)
{
    char res = c<<1;
    if(c & MSB_1BYTE)
    {
        res = res | LSB_1BYTE;
    }
    return res;
}

char rotateRight(char c)
{
    char res = c>>1;
    if(c & LSB_1BYTE)
    {
        res = res | MSB_1BYTE;
    }
    return res;
}


void sumBasedEncryption(char* buff, unsigned long lenght, int key, int enc)
{
    if(!enc)
    {
        key = -key;
    }
    for(unsigned long i = 0; i < lenght; i++)
    {
        buff[i] = (char)(((int)buff[i] + key) % 256);
    }
}

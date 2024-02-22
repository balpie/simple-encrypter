#include "criptData.h"

char rotateLeft(char c, int d)
{
    return (c<<d) | c >>(NUM_BITS - d);
}

char rotateRight(char c, int d)
{
    return (c>>d) | c <<(NUM_BITS - d);
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

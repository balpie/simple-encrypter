#include "../include/include.h"

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


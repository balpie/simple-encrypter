#include "criptData.h"


void sumBasedEncription(char* buff, unsigned long lenght, int key, int enc)
{
    if(enc == DECRYPT)
    {
        key = -key;
    }
    for(unsigned long i = 0; i < lenght; i++)
    {
        buff[i] = (buff[i] + key) % 256;
    }
}

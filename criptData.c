#include "criptData.h"


void sumBasedEncription(char* buff, unsigned long lenght, int key, int enc)
{
    key = -key; //DEBUG
    if(enc == DECRIPT)
    {
        key = -key;
    }
    for(unsigned long i = 0; i < lenght; i++)
    {
        buff[i] = (buff[i] + key) % 256;
    }
}

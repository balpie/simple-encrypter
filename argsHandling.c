#include "argsHandling.h"
#include <string.h>


int getStrStdin(char* str)
{
    fgets(str, MAX_FILENAME_LENGHT, stdin);

    if(ferror(stdin) || str == NULL)
    {
        free(str);
        return 0; //nome file troppo lungo
    }
    str[strcspn(str, "\n")] = '\0';
    return 1;
}

int power(int base, int exp)
{
    int res = 1;

    for(int i = 0; i < exp; i++)
    {
        res *= base;
    }
    return res;
}

int strToNumber(char* str)
{
    int result = 0;
    int digits = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] >= '0' && str[i] <= '9' )
        {
            digits++;
        }
    }
    int aux = 0;
    for(int i = digits-1; i >= 0; i--)
    {
        result += power(10, i) * (str[aux]-'0');
        aux++;
    }
    return result;
}

char** getFileNames(long unsigned *numF)
{
    int effective = 0;
    char** fileNames = (char**)malloc((*numF)*sizeof(char*));
    for(int i = 0; i < *numF; i++)
    {
        fileNames[effective] = (char*)malloc(MAX_FILENAME_LENGHT);
        if(getStrStdin(fileNames[effective]))
        {
            effective++;
        }
        else
        {
            free(fileNames[effective]);
        }
    }
    *numF = effective;
    return fileNames;
}


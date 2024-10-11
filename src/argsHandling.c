#include "../include/include.h"

int getStrStdin(char* str)
{
    fgets(str, MAX_STR_LENGTH, stdin);

    if(ferror(stdin) || str == NULL)
    {
        free(str);
        return 0; //nome file troppo lungo
    }
    str[strcspn(str, "\n")] = '\0';
    return 1;
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


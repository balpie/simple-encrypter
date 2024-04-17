#include "../include/include.h"

char* readFileContent(char* fileName, unsigned long *dim)
{
    FILE *readfp = fopen(fileName, "rb");

    if(readfp == NULL)
    {
        printf("%s non esiste\n", fileName);
        return NULL;
    }

    unsigned long dimFile;

    fseek(readfp, 0, SEEK_END);
    dimFile = ftell(readfp);
    fseek(readfp, 0, SEEK_SET);

    //printf("##################") ;
    //printf("Posizione Iniziale File: %ld", ftell(readfp));
    //printf("##################") ;

    char* buffer = (char*)malloc(dimFile);

    fread(buffer, 1, dimFile, readfp);
    *dim = dimFile;
    fclose(readfp);
    return buffer;
}

int writeFileContent(char* fileName, char* buffer, unsigned long len)
{
    if(fileName == NULL)
    {
        printf("impossibile creare file senza nome\n");
        return 0;
    }
    FILE *writefp = fopen(fileName, "wb");

    if(writefp != NULL)
    {
        fseek(writefp,0,SEEK_SET);
    }

    fwrite(buffer, 1, len, writefp);
    fclose(writefp);

    return 1;
}

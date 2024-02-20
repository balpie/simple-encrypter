#include "argsHandling.h"
#include "fileHandling.h"
#include "criptData.h"
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc < 3) //almeno modalità e numero file
    {
        printf("argomenti non sufficienti\n");
        printf("simple-enc -d | -e numfiles [key]\n");
        exit(-1);
    }
    int opt, mode;
    while((mode = getopt(argc, argv, "de"))!= -1)
    {
        switch (opt)
        {
        case 'd': mode = DECRYPT; break;
        case 'e': mode = ENCRYPT; break;
       // default:
       //     printf("wrong argument usage\n");
       //     exit(-1);
        }
    }

    unsigned long key, numFiles;
    numFiles = strToNumber(argv[2]);
    key = strToNumber(argv[3]);

    char **filesToEncript = getFileNames(&numFiles);

    for(int i = 0; i < numFiles; i++)
    {
        char* buff;
        char* newName = generateNewName(filesToEncript[i], mode);
        printf("nuovo nome per %s: %s\n", filesToEncript[i], newName);

        unsigned long dimFile;
        buff = readFileContent(filesToEncript[i], &dimFile);

        sumBasedEncription(buff, dimFile, key, mode);

        writeFileContent(newName, buff, dimFile);

        free(buff);
        free(newName);
    }

    for(int i = 0; i < numFiles; i++)
    {
        free(filesToEncript[i]);
    }
    free(filesToEncript);

    return 0;
}
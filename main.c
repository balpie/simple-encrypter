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

    opt = getopt(argc, argv, "de");
    switch (opt)
    {
        case 'd':
            mode = DECRYPT;
            break;
        case 'e':
            mode = ENCRYPT;
            break;
        default:
            printf("wrong mode argument\n");
            exit(-1);
    }


    if(mode == ENCRYPT) 
    {
        printf("Modalità: Encrypting\n");
    }
    else
    {
        printf("Modalità: Decrypting\n");
    }

    unsigned long numFiles;
    int key;
    numFiles = strToNumber(argv[2]);
    key = strToNumber(argv[3]);

    char **filesToEncript = getFileNames(&numFiles);

    for(int i = 0; i < numFiles; i++)
    {
        char* buff;
        //char* newName = generateNewName(filesToEncript[i], mode); DEPRECATED

        unsigned long dimFile;
        buff = readFileContent(filesToEncript[i], &dimFile);

        printf("dimensione %s: %ld\n", filesToEncript[i], dimFile);

        sumBasedEncryption(buff, dimFile, key, mode);

        writeFileContent(filesToEncript[i], buff, dimFile);

        free(buff);
        //free(newName);
    }

    for(int i = 0; i < numFiles; i++)
    {
        free(filesToEncript[i]);
    }
    free(filesToEncript);

    return 0;
}

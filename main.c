#include "argsHandling.h"
#include "fileHandling.h"
#include "criptData.h"


int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Numero argomenti errato\n");
        exit(-1);
    }

    unsigned long key, numFiles;
    key = strToNumber(argv[1]);
    numFiles = strToNumber(argv[2]);

    char **filesToEncript = getFileNames(&numFiles);

    for(int i = 0; i < numFiles; i++)
    {
        char* buff;
        char* newName = generateNewName(filesToEncript[i]);
        printf("nuovo nome per %s: %s\n", filesToEncript[i], newName);

        unsigned long dimFile;
        buff = readFileContent(filesToEncript[i], &dimFile);

        sumBasedEncription(buff, dimFile, key, ENCRIPT);

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
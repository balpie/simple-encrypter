#include <iostream>
#include <fstream>
#include <cstring>
#define MAX_STR_LENGHT 30

int main()
{
    int key;
    char inputFile[MAX_STR_LENGHT];
    std::cin>>inputFile>>key; 

    std::ifstream istream(inputFile, std::ios::binary);

    if(!istream.is_open()) 
    {
        std::cout<<"failed to open "<<inputFile<<"\n";
        return -1;
    }
    char outputFile[strlen(inputFile) + 3];
    strcpy(outputFile, inputFile);
    outputFile[strlen(inputFile)] = '.';
    outputFile[strlen(inputFile) + 1] = 'd';
    outputFile[strlen(inputFile) + 2] = '\0';
    std::ofstream ostream(outputFile, std::ios::binary);
   
    //trovo la dimensione del file
    istream.seekg(0, istream.end);
    int lenght = istream.tellg();
    istream.seekg(0, istream.beg);

    char buffer[lenght];
    istream.read(buffer, lenght);
    istream.close();

    for(int i = 0; i < lenght; i++)
    {
        buffer[i] = (buffer[i] + key) % 256;
    }

    ostream.write(buffer, lenght);
    ostream.close();
    return 0;
}

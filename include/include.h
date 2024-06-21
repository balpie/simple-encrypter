#ifndef INCLUDES
#define INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGHT 64
#define MAX_STR_LENGTH 1024

#define ENCRYPT 1
#define DECRYPT 0
#define NUM_BITS 8

//argsHandling
/**@brief Prende da input str di dim massima MAX_STR_LENGTH
 * @param puntatore a stringa già allocata
 * @return 1 se dimensione corretta, 0 altrimenti
 */
int getStrStdin(char* str);

/**@brief Converte i caratteri di str in int. Se la stringa non è
 *  composta da caratteri numerici il valore di ritorno sarà 0
 * @param stringa già allocata
 * @return la stringa convertita a int
 */
int strToNumber(char* str);

/**@brief prende da input numF stringhe
 * @param Numero di stringhe aspettate. Finita l'esecuzione numF
 * indicherà il numero di stringhe che sono state effettivamente allocate
 * @return vettore di stringhe trovate
 */
char** getFileNames(long unsigned *numF); 

/**@brief somma o sottrae key a ogni elemento di buff
 * @param stringa di dimensione lenght
 * @param dimensione di buff
 * @param 0 < key < 255, verrà sommato o sottratto ai buff[i]
 * @param indica se key verrà sommato sottratto 
 */
void sumBasedEncryption(char* buff, unsigned long length, 
                        int key, int enc);

//fileHandling
/**@brief scrive il contenuto del file in un buffer
 * @param nome del file
 * @param effetto collaterale: dim assumerà la dimensione del file
 * @return ritorna l'indirizzo del buffer con i byte del file
 */
char* readFileContent(char* fileName, long unsigned *dim);

/**@brief sovrascrive il contenuto di file con ciò che è contenuto in buffer
 * @param fileName nome del file
 * @param buffer contenente i byte da scrivere
 * @param len dimensionedel buffer
 * @return 1 se il file esiste, 0 altrimenti
 */
int writeFileContent(char* fileName, char *buffer, long unsigned len);

#endif





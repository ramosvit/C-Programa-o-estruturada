#include <stdlib.h>
char *avanca_palavra(char *frase, char *trecho) {
    char *ptr = strstr(frase, trecho); 

    if (ptr == NULL) {
        return NULL; 
    }

    int index = ptr - frase;

    char *resultado = (char *)malloc(sizeof(char) * (strlen(frase) - index + 1));

    strcpy(resultado, &frase[index]);

    return resultado;
}
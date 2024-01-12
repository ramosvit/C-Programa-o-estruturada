#include <stdio.h>

int main() {
    char texto[100];
    int i, palavras;


    fgets(texto, sizeof(texto), stdin);


    palavras = 0;
    

    int dentroDaPalavra = 0;

    for (i = 0; texto[i] != '\0'; i++) {

        if (texto[i] == ' ' || texto[i] == '\n' || texto[i] == '\t') {
            dentroDaPalavra = 0;
        }

        else if (!dentroDaPalavra) {
            dentroDaPalavra = 1;
            palavras++;
        } 
    }

    printf("%d\n", palavras);

    return 0;
}
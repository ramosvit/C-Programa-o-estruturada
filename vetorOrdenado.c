#include <stdio.h>

int main() {
    int vetor[100];  
    int tamanho = 0; 

    while (1) {
        int numero;
        scanf("%d", &numero);

//colocar um break quando digitar numero -1
        if (numero == -1) {
            break;  
        }

        
        int x = 0;
        while (x < tamanho && vetor[x] < numero) {
            x++;
        }

       
        for (int i = tamanho; i > x; i--) {
            vetor[i] = vetor[i - 1];
        }

        
        vetor[x] = numero;
        tamanho++;

       
        printf("\n");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");
    }

    return 0;
}
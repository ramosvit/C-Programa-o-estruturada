// Não declare vetor com colchetes
// Use malloc para alocar o vetor (e lembre-se de usar free para liberar a memória alocada com malloc)
#include <stdio.h>
#include <stdlib.h>

void insertSorted(double *vetor, int tamanho, double numero) {
    int i = tamanho - 2;
    while (i >= 0 && vetor[i] > numero) {
        vetor[i + 1] = vetor[i];
        i--;
    }
    vetor[i + 1] = numero;
}

void printVetor(double *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] != 0) {
            printf("%.1lf ", vetor[i]);
        }
    }
    printf("\n");
}

int main() {
    int tamanho;
    scanf("%d", &tamanho);

    double *vetor = (double *)malloc(tamanho * sizeof(double));
    if (vetor == NULL) {
        return 1;
    }

    int count = 0;
    double numero;
    while (1) {
        scanf("%lf", &numero);

        if (numero == -1) {
            break;
        }

        insertSorted(vetor, count + 1, numero);
        count++;
        printVetor(vetor, count);
    }

    free(vetor);
    return 0;
}
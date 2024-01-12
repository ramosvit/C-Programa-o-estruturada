//#include "primos.h"
#include <stdlib.h>
#include <math.h>

int eh_primo(int numero) {
    if (numero <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(numero); i++) {
        if (numero % i == 0) {
            return 0;
        }
    }
    return 1;
}

void separar_numeros_primos(ListaNumeros *lista) {
    int count_primos = 0;
    for (int i = 0; i < lista->n_numeros; i++) {
        if (eh_primo(lista->numeros[i])) {
            count_primos++;
        }
    }

    if (count_primos > 0) {
        lista->primos = (int *)malloc(count_primos * sizeof(int));
        lista->n_primos = 0;

        int count_nao_primos = 0;
        int *nao_primos = (int *)malloc((lista->n_numeros - count_primos) * sizeof(int));

        for (int i = 0; i < lista->n_numeros; i++) {
            if (eh_primo(lista->numeros[i])) {
                lista->primos[lista->n_primos++] = lista->numeros[i];
            } else {
                nao_primos[count_nao_primos++] = lista->numeros[i];
            }
        }

        for (int i = 0; i < count_nao_primos; i++) {
            lista->numeros[i] = nao_primos[i];
        }

        lista->n_numeros = count_nao_primos;

        free(nao_primos);
    }
}
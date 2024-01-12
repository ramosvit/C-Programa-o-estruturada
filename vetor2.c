//#include "vetor.h"
#include <stdlib.h>

int* duplica_impares(int *v, int n_entrada, int *n_retorno) {
    int count_impares = 0;


    for (int i = 0; i < n_entrada; i++) {
        if (v[i] % 2 != 0) {
            count_impares++;
        }
    }

   
    int *novo_vetor = (int*)malloc((n_entrada + count_impares) * sizeof(int));
    if (novo_vetor == NULL) {
        *n_retorno = 0;
        return NULL; 
    }

    int index = 0;

  
    for (int i = 0; i < n_entrada; i++) {
        novo_vetor[index++] = v[i];
        if (v[i] % 2 != 0) {
            novo_vetor[index++] = v[i];
        }
    }

    *n_retorno = n_entrada + count_impares;
    return novo_vetor;
}
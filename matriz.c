//#include "matriz.h"
#include <stdlib.h>
double **cria_matriz(int n_linhas, int n_colunas) {

    double **matriz = (double **)malloc(n_linhas * sizeof(double *));
    
  
  
    if (matriz == NULL) {
        return NULL;
    }


    for (int i = 0; i < n_linhas; i++) {
        
        matriz[i] = (double *)malloc(n_colunas * sizeof(double));
        
   
        if (matriz[i] == NULL) {
            
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }



        for (int j = 0; j < n_colunas; j++) {
            matriz[i][j] = (i + j) % 2;
        }
    }
    
    return matriz;
}


void liberar_matriz(double **matriz, int n_linhas) {

    for (int i = 0; i < n_linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
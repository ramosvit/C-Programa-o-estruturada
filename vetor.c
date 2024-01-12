//#include "vetor.h"
#include <stdlib.h>
int intercala_vetores(int *v_a, int n_a, int *v_b, int n_b, int **v) {
    int *resultado = (int *)malloc((n_a + n_b) * sizeof(int)); 

    if (resultado == NULL) {
        return 0; 
    }

    int index_a = 0, index_b = 0, index_resultado = 0;


    while (index_a < n_a && index_b < n_b) {
        if (v_a[index_a] <= v_b[index_b]) {
            resultado[index_resultado] = v_a[index_a];
            index_a++;
        } else {
            resultado[index_resultado] = v_b[index_b];
            index_b++;
        }
        index_resultado++;
    }


    while (index_a < n_a) {
        resultado[index_resultado] = v_a[index_a];
        index_a++;
        index_resultado++;
    }


    while (index_b < n_b) {
        resultado[index_resultado] = v_b[index_b];
        index_b++;
        index_resultado++;
    }

    *v = resultado; 

    return index_resultado; 
}
#include <stdio.h>
#include <stdlib.h>

int** multiplicar_matrizes(int** A, int** B, int n_linhas_A, int n_colunas_A, int n_linhas_B, int n_colunas_B) {
    if (n_colunas_A != n_linhas_B) {
        return NULL;
    }

    int** resultado = (int**)malloc(n_linhas_A * sizeof(int*));

    for (int i = 0; i < n_linhas_A; i++) {
        resultado[i] = (int*)malloc(n_colunas_B * sizeof(int));
        for (int j = 0; j < n_colunas_B; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < n_colunas_A; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return resultado;
}

void liberar_matriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int n_linhas_A, n_colunas_A;
    scanf("%d %d", &n_linhas_A, &n_colunas_A);

    int** A = (int**)malloc(n_linhas_A * sizeof(int*));
    for (int i = 0; i < n_linhas_A; i++) {
        A[i] = (int*)malloc(n_colunas_A * sizeof(int));
        for (int j = 0; j < n_colunas_A; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int n_linhas_B, n_colunas_B;
    scanf("%d %d", &n_linhas_B, &n_colunas_B);

    int** B = (int**)malloc(n_linhas_B * sizeof(int*));
    for (int i = 0; i < n_linhas_B; i++) {
        B[i] = (int*)malloc(n_colunas_B * sizeof(int));
        for (int j = 0; j < n_colunas_B; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int** resultado = multiplicar_matrizes(A, B, n_linhas_A, n_colunas_A, n_linhas_B, n_colunas_B);

    if (resultado == NULL) {
        printf("Multiplicação inválida!\n");
    } else {
        for (int i = 0; i < n_linhas_A; i++) {
            for (int j = 0; j < n_colunas_B; j++) {
                printf("%d ", resultado[i][j]);
            }
            printf("\n");
        }
        liberar_matriz(resultado, n_linhas_A);
    }

    liberar_matriz(A, n_linhas_A);
    liberar_matriz(B, n_linhas_B);

    return 0;
}
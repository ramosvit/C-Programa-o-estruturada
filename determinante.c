//#include "determinante.h"
#include <stdio.h>

#include <stdio.h>

void remove_primeira_linha_e_coluna_c(int n, float m_entrada[n][n], float m_saida[n - 1][n - 1], int c) {
    int row_dest = 0, col_dest = 0;
    for (int row = 1; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (col != c) {
                m_saida[row_dest][col_dest++] = m_entrada[row][col];
                if (col_dest == n - 1) {
                    col_dest = 0;
                    row_dest++;
                }
            }
        }
    }
}

float calcula_determinante(int n, float m_entrada[n][n]) {
    if (n == 1) {
        return m_entrada[0][0];
    }

    float det = 0;
    float submatriz[n - 1][n - 1];

    for (int j = 0; j < n; j++) {
        float submatriz[n - 1][n - 1];
        remove_primeira_linha_e_coluna_c(n, m_entrada, submatriz, j);
        det += m_entrada[0][j] * (j % 2 == 0 ? 1 : -1) * calcula_determinante(n - 1, submatriz);
    }

    return det;
}

int main() {
    int n;
    scanf("%d", &n);

    float m_entrada[n][n];

    // Lendo a matriz de entrada
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &m_entrada[i][j]);
        }
    }

    float determinante = calcula_determinante(n, m_entrada);
    printf("%.2f\n", determinante);

    return 0;
}
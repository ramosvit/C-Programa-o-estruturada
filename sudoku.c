#include <stdio.h>

int validando(int board[9][9]) {
    int linha, coluna, numero;
    

    for (linha = 0; linha < 9; linha++) {
        int seen[10] = {0};
        for (coluna = 0; coluna < 9; coluna++) {
            numero = board[linha][coluna];
            if (numero != 0 && seen[numero] == 1) {
                return 0;
            }
            seen[numero] = 1;
        }
    }

    for (coluna = 0; coluna < 9; coluna++) {
        int seen[10] = {0};
        for (linha = 0; linha < 9; linha++) {
            numero = board[linha][coluna];
            if (numero != 0 && seen[numero] == 1) {
                return 0;
            }
            seen[numero] = 1;
        }
    }
    

    for (int block = 0; block < 9; block++) {
        int seen[10] = {0};
        int start_linha = (block / 3) * 3;
        int start_coluna = (block % 3) * 3;
        for (linha = start_linha; linha < start_linha + 3; linha++) {
            for (coluna = start_coluna; coluna < start_coluna + 3; coluna++) {
                numero = board[linha][coluna];
                if (numero != 0 && seen[numero] == 1) {
                    return 0; 
                }
                seen[numero] = 1;
            }
        }
    }
    
    return 1; 
}

int main() {
    int board[9][9];
    
    for (int linha = 0; linha < 9; linha++) {
        for (int coluna = 0; coluna < 9; coluna++) {
            scanf("%d", &board[linha][coluna]);
        }
    }
    
    if (validando(board)) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }
    
    return 0;
}
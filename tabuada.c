#include <stdio.h>
#include <stdlib.h>

char* decToBinary(int num) {
    // Converter decimal para binário
    char* binary = (char*)malloc(32 * sizeof(char));
    int i = 0;
    while (num > 0) {
        binary[i++] = (num % 2) + '0';
        num = num / 2;
    }
    binary[i] = '\0';

    // Reverter a string binária
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = binary[start];
        binary[start] = binary[end];
        binary[end] = temp;
        start++;
        end--;
    }
    return binary;
}

void tabuada_binaria(int numero) {
    for (int i = 1; i <= 10; i++) {
        int resultado = numero * i;
        char* bin_i = decToBinary(i);
        char* bin_numero = decToBinary(numero);
        char* bin_resultado = decToBinary(resultado);

        printf("%sx%s=%s\n", bin_i, bin_numero, bin_resultado);

        free(bin_i);
        free(bin_numero);
        free(bin_resultado);
    }
}

int main() {
    int numero_decimal;
    scanf("%d", &numero_decimal);
    tabuada_binaria(numero_decimal);
    return 0;
}
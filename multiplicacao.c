#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int rows, int columns) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }
    return matrix;
}

void deallocateMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void readMatrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiplyMatrices(int **matrixA, int **matrixB, int **resultMatrix, int rowsA, int columnsA, int columnsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < columnsA; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void printMatrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowsA, columnsA;
    scanf("%d %d", &rowsA, &columnsA);

    int **matrixA = allocateMatrix(rowsA, columnsA);
    readMatrix(matrixA, rowsA, columnsA);

    int rowsB, columnsB;
    scanf("%d %d", &rowsB, &columnsB);

    int **matrixB = allocateMatrix(rowsB, columnsB);
    readMatrix(matrixB, rowsB, columnsB);

    if (columnsA != rowsB) {
        printf("Impossivel multiplicar as matrizes. Dimensoes incompativeis.\n");
        deallocateMatrix(matrixA, rowsA);
        deallocateMatrix(matrixB, rowsB);
        return 1;
    }

    int **resultMatrix = allocateMatrix(rowsA, columnsB);
    multiplyMatrices(matrixA, matrixB, resultMatrix, rowsA, columnsA, columnsB);

    printf("Resultado da multiplicacao:\n");
    printMatrix(resultMatrix, rowsA, columnsB);

    deallocateMatrix(matrixA, rowsA);
    deallocateMatrix(matrixB, rowsB);
    deallocateMatrix(resultMatrix, rowsA);

    return 0;
}
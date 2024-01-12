#include <stdio.h>
#include <stdlib.h>

void intercala_ordem_crescente(int *vetor1, int n1, int *vetor2, int n2) {
    int *p1 = vetor1;
    int *p2 = vetor2;

    while (n1 > 0 && n2 > 0) {
        if (*p1 <= *p2) {
            printf("%d ", *p1);
            p1++;
            n1--;
        } else {
            printf("%d ", *p2);
            p2++;
            n2--;
        }
    }

    while (n1 > 0) {
        printf("%d ", *p1);
        p1++;
        n1--;
    }

    while (n2 > 0) {
        printf("%d ", *p2);
        p2++;
        n2--;
    }

    printf("\n");
}

int main() {
    int n1, n2;
    scanf("%d", &n1);

    int *vetor1 = (int *)malloc(sizeof(int) * n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", vetor1 + i);
    }

    scanf("%d", &n2);

    int *vetor2 = (int *)malloc(sizeof(int) * n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", vetor2 + i);
    }

    intercala_ordem_crescente(vetor1, n1, vetor2, n2);

    free(vetor1);
    free(vetor2);

    return 0;
}
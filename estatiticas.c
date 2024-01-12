#include <stdio.h>

int main() {
    int num_int;
    scanf("%d", &num_int);
    
   
float menor = 100;
    float maior = 0;
    float soma = 0.0;
    
   
for (int i = 0; i < num_int; i++) {
        float valor;
        scanf("%f", &valor);
        soma += valor;
        if (valor < menor) {
            menor = valor;
        }
        if (valor > maior) {
            maior = valor;
        }
    
            maior = valor;
    }
    
  
    float media = soma / num_int;
    
    
    printf("%.2f\n", menor);
    printf("%.2f\n", maior);
    printf("%.2f\n", media);
    
return 0;
}
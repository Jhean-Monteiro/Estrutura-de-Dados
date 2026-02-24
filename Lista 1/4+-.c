#include <stdio.h>

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero > 0) {
        printf("O numero é positivo\n");
    } 
    else if (numero < 0) {
        printf("O numero é negativo\n");
    } 
    else {
        printf("ZERO\n");
    }

    return 0;
}
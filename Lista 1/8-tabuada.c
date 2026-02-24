// Faça um programa que leia um número inteiro e mostre sua tabuada de 1 a 10.

#include <stdio.h>

int main() {
    int numero;
    int i;

    printf("Digite um numero para ver a tabuada: ");
    scanf("%d", &numero);

    printf("\nTabuada do %d:\n", numero);
    printf("_________________________________\n");

    i = 1;
    while (i <= 10) {
        printf("%d x %d = %d\n", numero, i, numero * i);
        i = i + 1;
    }
    return 0;
}
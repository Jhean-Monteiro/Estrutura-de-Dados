// Faça um programa que leia um número inteiro e informe se ele é par ou ímpar.

#include <stdio.h>

int main () {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("O numero %d é par\n", numero);
    } else {
        printf("O numero %d é impar\n", numero);
    }
    return 0;
}
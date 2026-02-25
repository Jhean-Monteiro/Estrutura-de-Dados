// Faça um programa que leia um número e utilize uma função para verificar se ele é par.

#include <stdio.h>

int EhPar(int n) {
    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (EhPar(numero) == 1) {
        printf("%d é PAR\n", numero);
    } else {
        printf("%d é IMPAR\n", numero);
    }
}
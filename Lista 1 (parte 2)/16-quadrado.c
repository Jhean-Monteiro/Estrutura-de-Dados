// Desenvolva um programa que utilize uma função para calcular o quadrado de um número.

#include <stdio.h>

int quadrado(int n) {
    return n * n;
}

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    printf("O quadrado de %d é %d\n", numero, quadrado(numero));

    return 0;
}
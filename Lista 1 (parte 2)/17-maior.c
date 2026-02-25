// Crie um programa que leia dois números e utilize uma função para retornar o maior.

#include <stdio.h>

int maior(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    int num1, num2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    printf("O maior é: %d\n", maior(num1, num2));

    return 0;
}
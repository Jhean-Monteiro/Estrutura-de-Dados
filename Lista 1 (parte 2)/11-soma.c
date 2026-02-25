// Crie um programa que leia 5 números inteiros e mostre a soma deles.

#include <stdio.h>

int main() {
    int num1, num2, num3, num4, num5;
    int soma;

    printf("Digite 5 numeros inteiros:\n");

    printf("Primeiro numero: ");
    scanf("%d", &num1);

    printf("Segundo numero: ");
    scanf("%d", &num2);

    printf("Terceiro numero: ");
    scanf("%d", &num3);

    printf("Quarto numero: ");
    scanf("%d", &num4);

    printf("Quinto numero: ");
    scanf("%d", &num5);

    soma = num1 + num2 +num3 +num4 + num5;

    printf("A soma dos 5 numeros é: %d\n", soma);
    return 0;
}
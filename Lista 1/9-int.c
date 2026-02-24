// Desenvolva um programa que leia um número inteiro e mostre os números de 1 até ele.

#include <stdio.h>

int main() {
    int numero;
    int i;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Digite um número maior que 0!\n");
        return 0;
    }

    printf("Numeros de 1 até %d:\n", numero);

    i = 1;
    while (i <= numero) {
        printf("%d ", i);
        i = i+1;
    }
    printf("\n");
    return 0;
}
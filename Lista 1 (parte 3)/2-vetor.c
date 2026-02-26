// Faça um programa que leia 5 números em um vetor e mostre-os na tela.

#include <stdio.h>

int main() {
    int vetor[5];
    int i;

    printf("Digite 5 numeros inteiros:\n");

    for (i = 0; i < 5; i++) {
        printf("%do numero: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("\nNumeros digitados:\n");

    for (i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
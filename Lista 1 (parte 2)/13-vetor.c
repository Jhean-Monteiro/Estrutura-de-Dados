// Escreva um programa que leia um vetor de 10 posições e mostre seus valores.

#include <stdio.h>

int main() {
    int vetor[10];
    int i;

    printf("Digite 10 numeros inteiros:\n");

    for (i = 0; i < 10; i++) {
        printf("Posição %d: ", i+1);
        scanf("%d", &vetor[i]);
    }
    printf("\nValores Digitados:\n");

    for (i = 0; i < 10; i++) {
        printf("Posicao %d: %d\n", i+1, vetor[i]);
    }

    return 0;
}
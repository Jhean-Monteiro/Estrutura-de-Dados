// Faça um programa que conte quantos números pares existem em um vetor.

#include <stdio.h>

int main() {
    int vetor[5];
    int i;
    int contador = 0;

    printf("Digite 5 numeros inteiros:\n");

    for (i = 0; i < 5; i++) {
        printf("%do: ", i+1);
        scanf("%d", &vetor[i]);

        if (vetor[i] % 2 == 0) {
            contador ++;
        }
    }

    printf("\nquantidade de numeros pares: %d\n", contador);

    return 0;
}
// Crie um programa que encontre o maior valor em um vetor de 5 posições.

#include <stdio.h>

int main() {
    int vetor[5];
    int i;
    int maior;

    printf("Digite 5 numeros:\n");

    for (i = 0; i < 5; i++) {
        printf("%do: ", i+1);
        scanf("%d", &vetor[i]);

    }

    maior = vetor[0]; // assume que o primeiro é o maior

    for(i = 1; i < 5; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    printf("\nO maior valor é: %d\n", maior);

    return 0;
}
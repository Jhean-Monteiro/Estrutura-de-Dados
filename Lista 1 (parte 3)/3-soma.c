// Desenvolva um programa que calcule a soma dos elementos de um vetor.

#include <stdio.h>

int main() {
    int vetor[5];
    int i;
    int soma = 0;

    printf("Digite 5 numeros:\n");

    for (i = 0; i < 5; i++) {
        printf("%do ", i + 1);
        scanf("%d", &vetor[i]);
        soma = soma + vetor[i];
    }

    printf("\nsoma dos elementos: %d\n", soma);

    return 0;
}

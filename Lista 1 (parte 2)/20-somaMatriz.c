// Crie um programa que leia uma matriz 2x2 e calcule a soma de todos os valores.

#include <stdio.h>

int main() {
    int matriz[2][2];
    int i, j;
    int soma = 0;

    printf("Digite os 4 elementos da matriz 2x2:\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            soma = soma + matriz[i][j];
        }
    }

    printf("\nSoma de todos os elementos: %d\n", soma);

    return 0;
}
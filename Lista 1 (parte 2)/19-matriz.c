// Escreva um programa que leia uma matriz 2x2 e mostre seus elementos.

#include <stdio.h>

int main() {
    int matriz[2][2];
    int i, j;

    printf("Digite os elementos da matriz 2x2:\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz digitada:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d", matriz[i][j]); // mostra cada elemento
        }
        printf("\n"); // pula linha a cada elemento
    }

    return 0;
}
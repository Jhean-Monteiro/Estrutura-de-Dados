// Faça um programa que leia os valores de uma matriz 2x2.

#include <stdio.h>

int main() {
    int matriz[2][2];
    int i, j;
    printf("Digite os 4 elementos da matriz 2x2:\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Elemento [%d][%d]", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\nMatriz lida\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
// Declare uma matriz 3x3 e inicialize todos os valores com zero.

#include <stdio.h>

int main() {
    int matiz[3][3] = {0};

    printf("Matriz 3x3 inicializada com zero:\n");
    int i,j;
    for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {         
        printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;

}
#include <stdio.h>
#include <stdlib.h> // malloc

int main() {
    int i, n;
    int *vetor;
    
    printf("entre com o tamanho do vetor: ");
    scanf("%d", &n);
    
    // alocando posicoes de memoria
    vetor = (int*)malloc(n*sizeof(int));
    
    if (vetor == NULL){
        printf("erro de alocação de memória");
        return 1;
    }
    for (i = 0; i<n;i++){
        vetor[i] = i * 20;
        printf("Posição %d: elemento %d\n", i, vetor[i]);
    }
    
    free(vetor);
    printf("Posição %d: elemento %d\n", i, vetor[i]);
    return 0;
}
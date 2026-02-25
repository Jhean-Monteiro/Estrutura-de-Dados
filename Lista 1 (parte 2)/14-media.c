// Crie um programa que leia um vetor de 5 números e calcule a média.


#include <stdio.h>
#include <locale.h>

int main() {
    float vetor[5];
    float soma = 0;
    float media;
    int i;

    printf("Digite 5 numeros (pode ser float):\n");

    for (i = 0; i < 5; i++) {
        printf("%do numero: ", i+1);
        scanf("%f", &vetor[i]);
        soma = soma + vetor[i];
    }
    media = soma/5;

    printf("\nA media dos 5 numeros é: %.2f\n", media);

    return 0;
}
// Escreva um programa que leia três notas e calcule a média aritmética.

#include <stdio.h>

int main() {
    float nota1;
    float nota2;
    float nota3;
    float media;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;
    printf("A media das notas é: %.2f\n", media);

    return 0;
}
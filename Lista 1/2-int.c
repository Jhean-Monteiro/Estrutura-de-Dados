// Faça um programa que leia um número inteiro e mostre esse número na tela.


#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    printf("Você digitou: %d\n", numero);

    return 0;
}
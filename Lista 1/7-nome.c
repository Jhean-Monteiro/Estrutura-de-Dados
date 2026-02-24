// Crie um programa que leia o nome e a idade de uma pessoa e mostre esses dados.

#include <stdio.h>

int main () {
    char nome[50];
    int idade;

    printf("Digite seu nome: ");
    scanf("%s", nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Dados informados:\n");
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);

    return 0;
}
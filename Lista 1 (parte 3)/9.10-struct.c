// Faça um programa que leia os dados de uma struct e mostre na tela.

#include <stdio.h>

struct Pessoa { //tipo personalizado
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa p; // variavel do tipo struct Pessoa

    printf("Digite o nome da pessoa: ");
    scanf("%s", p.nome);

    printf("Digite a idade da pessoa: ");
    scanf("%d", &p.idade);

    printf("\nDados da pessoa:\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d anos\n", p.idade);
}


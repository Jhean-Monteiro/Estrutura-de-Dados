// Crie um programa que utilize uma struct para armazenar nome e idade de uma pessoa.

#include <stdio.h>

struct Pessoa { //tipo personalizado
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa p; // variavel do tipo struct Pessoa

    printf("\nStruct criada com sucesso!\n");
    return 0;
}
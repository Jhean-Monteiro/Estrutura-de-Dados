#include <stdio.h>

struct Pessoa {
    char nome[20];
    int idade;
    float altura;
};

int main() {
    struct Pessoa pessoa1;
    pessoa1.nome = "Pedro";
    pessoa1.idade = 21;
    pessoa1.altura = 1.7;
    
    printf("Idade do Pedro: %d", pessoa1.idade);
    
    // ponteiro para struct
    struct Pessoa *ptr = &pessoa1;
    
    // jeito facil de acessar struct com ponteiro
    printf("Altura do Pedro é: %f" ptr->altura)
    
    // jeito difícil
    printf("A idade do pedro é: %d", (*ptr).idade)
    
    return 0;
}
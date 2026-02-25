// Faça um programa que leia um número inteiro e calcule a soma dos números pares até ele.

#include <stdio.h>

int main() {
    int numero, i, soma = 0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if(numero <= 0) {
        printf("Digite um numero maior que 0!\n");
        return 0;
    }

    for (i = 1; i<= numero; i++) {
        if (i % 2 == 0) soma = soma + i;
    }

    printf("Soma dos pares de 1 ate %d é: %d\n", numero, soma);

    return 0;
}
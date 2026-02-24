// Faça um programa que leia um número e calcule seu fatorial (usando for).

#include <stdio.h>

int main() {
    int numero;
    int fatorial = 1;
    int i;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Não existe fatorial de numero negativo!\n");
        return 0;
    }

    for (i = 1; i <= numero; i++) {
        fatorial = fatorial * i;
    }
    printf("%d! = %d\n", numero, fatorial);

    return 0;
}
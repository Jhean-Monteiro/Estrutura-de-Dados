// Faça um programa que leia 5 números e informe qual é o maior.

#include <stdio.h>

int main() {
    int num;
    int maior;
    int i;

    printf("Digite 5 numeros:\n");

    printf("1o numero: ");
    scanf("%d", &num);
    maior = num; //por enquanto

    for (i = 2; i <= 5; i++) {
        printf("%do numero: ", i);
        scanf("%d", &num);

        if (num > maior) {
            maior = num;
        }
    }
    printf("O maior numero digitado foi: %d\n", maior);

    return 0;
}
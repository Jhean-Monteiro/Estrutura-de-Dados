#include <stdio.h>

int main() {
    int numero1;
    int numero2;
    int soma;

    printf("Digite o primeiro numero: ");
    scanf("%d", &numero1);

    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);

    soma = numero1 + numero2;

    printf("A soma é: %d\n", soma);

    return 0;
}
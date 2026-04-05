/* 
Desenvolva um código em C para manipular uma pilha. Seu
código deve inserir, remover, verificar se a pilha está cheia e verificar
se a pilha está vazia. É necessário uma opção de entrada no main() para
definir o tamanho máximo que a pilha (por exemplo 10 elementos) e os
elementos que a pilha terá (n-1, ou seja, pelo exemplo 10-1 = 9
elementos). Em seguida, deve-se informar no terminal todos os
elementos da pilha, se a pilha está vazia, se a pilha está cheia, incluir
um elemento (qualquer valor) e informar no terminal a nova sequência,
remover um elemento e informar no terminal a nova sequência.
PROIBIDO O USO DE BIBLIOTECAS COMO STACK
*/

#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n); // lê o tamanho máximo da pilha
    int p[n], t = -1; // cria a pilha e topo começa em -1 (vazia)

    for(int i = 0; i < n-1; i++){ // insere os n-1 elementos iniciais
        scanf("%d", &p[++t]);
    }

    for(int i = 0; i <= t; i++) // mostra a pilha inicial
        printf("%d ", p[i]);
    printf("\n");

    if(t == -1) // verifica se está vazia
        printf("vazia\n");
    else
        printf("nao vazia\n");

    if(t == n-1) // verifica se está cheia
        printf("cheia\n");
    else
        printf("nao cheia\n");

    int v;
    scanf("%d", &v); // lê o novo valor
    p[++t] = v; // insere no topo (push)

    for(int i = 0; i <= t; i++) // mostra pilha após inserir
        printf("%d ", p[i]);
    printf("\n");

    t = t - 1; // remove o topo (pop)

    for(int i = 0; i <= t; i++) // mostra pilha final
        printf("%d ", p[i]);
    printf("\n");

    return 0;
}
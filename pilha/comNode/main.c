#include <stdio.h>
#include <stdlib.h>

 // ps: vou usar uma pilha de pratos como exemplo
struct No {
    int valor; // guarda o número do prato 
    struct No *proximo; // ponteiro para o prato que está abaixo desse
};

struct Pilha {
    struct No *topo; // ponteiro que vai apontar para o prato que está no topo
};



void empilhar(struct Pilha *p, int num) {
    struct No *novo = (struct No*) malloc(sizeof(struct No)); // aloca memória para o novo nó que será inserido no topo
    novo->valor = num; // coloca o número dentro do espaço 'valor' do novo nó
    
    novo->proximo = p->topo; // o novo 'olha' pra baixo e segura o endereço de quem era o topo até agora (o ponteiro *proximo do No atual vai apontar para o topo anterior (ou seja, vai ser empilhado acima dele))
    
    p->topo = novo; // o ponteiro *topo agora aponta para o novo No 
    
    printf("empilhado: %d\n", num);
}

void desempilhar(struct Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return;
    }
    
    struct No *aux = p->topo; // auxilixsr que segura o endereço do topo atual para ele não se perder no free()
    
    printf("Desempilhado: %d\n", aux->valor); // Mostra o valor que vai sumir
    
    p->topo = p->topo->proximo; // o topo atual recebe o endereço para onde o *proximo aponta (que é o prato de baixo), ou seja, o topo agora é o prato anterior
    
    free(aux);
    
}
    
    
int main() {
    struct Pilha minhaPilha; // cria a variavel da pilha
        
    minhaPilha.topo = NULL; // define que a pilha começa vazia (topo aponta para nada)
        
    printf("====== TESTANDO A PILHA ======\n");
        
    empilhar(&minhaPilha, 1); // adiciona o primeiro prato na base
    empilhar(&minhaPilha, 2);
    empilhar(&minhaPilha, 3);
    empilhar(&minhaPilha, 4);
    desempilhar(&minhaPilha);
}
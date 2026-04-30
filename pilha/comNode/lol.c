#include <stdio.h>
#include <stdlib.h>


struct No {
    int valor;
    struct No *proximo;
};

struct Pilha {
    struct No *topo;
    struct No *base;
    int count;
};

void exibir(struct Pilha *p){
    printf("Pilha: ");
    while (p->count != 0) {
        printf("[%d]->", p->topo->valor);
        p->topo = p->topo->proximo;
        p->count--;
    }
}

void adicionar(struct Pilha *p, int num) {
    struct No *novo = malloc(sizeof(struct No));
    novo->valor = num;
    novo->proximo = p->topo;
    if (p->topo == NULL) {
        p->base = novo;
        p->base->proximo = p->base;
    }
    p->topo = novo;
    p->base->proximo = novo;
    
    printf("Adicionado: %d\n", num);
    p->count++;
}

void remover(struct Pilha *p) {
    if (p->topo->proximo == NULL) return;
    
    struct No *aux = p->topo;
    p->topo = p->topo->proximo;
    printf("Removido: %d\n", aux->valor);
    free(aux);
    p->count--;
}


int main()
{
    struct Pilha minhaPilha = {NULL, NULL};
    adicionar(&minhaPilha, 10); 
    adicionar(&minhaPilha, 20); 
    adicionar(&minhaPilha, 30); 
    adicionar(&minhaPilha, 50); 
    adicionar(&minhaPilha, 60); 
    adicionar(&minhaPilha, 30);
    remover(&minhaPilha);
    adicionar(&minhaPilha, 40);
   
    exibir(&minhaPilha);

    return 0;
}

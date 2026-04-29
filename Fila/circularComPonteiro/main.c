#include <stdio.h>
#include <stdlib.h>

struct No {
    struct No *proximo;
    int valor;
};

struct Fila {
    struct No *fim;
    struct No *inicio;
};


void exibirFila(struct Fila *f) {
    if (f->inicio == NULL) {
        printf("Fila Vazia.\n");
        return;
    }
    
    struct No *temp = f->inicio; // ponteiro temporario
    printf("Fila Circular: \n");
    
    do {
        printf("[%d] ", temp->valor); // exibe valor atual
        temp = temp->proximo;
    } while (temp != f->inicio); //para quando der a volta completa e chegar no inicio dnv
    printf("\n");
}


void enfileirar(struct Fila *f, int num) {
    struct No *novo = malloc(sizeof(struct No));
    novo->valor = num;
    
    if (f->inicio == NULL) { // caso 1: fila vazia
        f->inicio = novo;
        f->fim = novo;
        novo->proximo = novo; // o novo aponta para ele mesmo
    } else { // caso 2: já tinha gente na fila
        f->fim->proximo = novo;
        f->fim = novo;
        f->fim->proximo = f->inicio; // o novo fim aponta para o início (um círculo)
    }
    
    printf("Enfileiradooo: %d\n", num);
}


void desenfileirar(struct Fila *f) {
    if (f->inicio == NULL) {
        printf("fila vazia\n");
        return;
    }
    
    struct No *aux = f->inicio;
    if (f->inicio == f->fim) { // SÓ TINHA UM ELEMENTO NA FILA
        f->inicio = NULL;
        f->fim = NULL;
        
    } else { // MAIS DE UM ELEMENTO... 
        f->inicio = f->inicio->proximo;
        f->fim->proximo = f->inicio;
    }
    
    printf("Removidoooo: %d\n", aux->valor);
    free(aux);
}


int main() {
    struct Fila queue = {NULL, NULL};
    enfileirar(&queue, 1);
    enfileirar(&queue, 2);
    enfileirar(&queue, 3);
    exibirFila(&queue); 
    desenfileirar(&queue);
    exibirFila(&queue); 
    enfileirar(&queue, 4);
    exibirFila(&queue); 
    desenfileirar(&queue);
    exibirFila(&queue); 
    enfileirar(&queue, 5);
    exibirFila(&queue); 
    desenfileirar(&queue);
    exibirFila(&queue); 
    enfileirar(&queue, 6);
    exibirFila(&queue); 
    desenfileirar(&queue);
    exibirFila(&queue); 
    enfileirar(&queue, 7);
    exibirFila(&queue); 
    desenfileirar(&queue);
    exibirFila(&queue); 
    return 0;
}
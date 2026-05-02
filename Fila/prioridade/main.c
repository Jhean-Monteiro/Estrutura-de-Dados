#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    int prioridade; // quanto maior o numero, mais 'urgente'
    struct No *proximo;
};

struct Fila {
    struct No *inicio; // o inicio sempre será o de maior prioridade
};

void inserir(struct Fila *f, int val, int prio) {
    struct No *novo = malloc(sizeof(struct No));
    novo->valor = val;
    novo->prioridade = prio;
    novo->proximo = NULL;
    
    
    // CASO !: a fila está vazia ou o novo tem prioridade maior que o primeiro
    if(f->inicio == NULL || prio > f->inicio->prioridade) {
        novo->proximo = f->inicio;
        f->inicio = novo;
    } else { // CASO 2: procurar o lugar certo no meio da fila 
        struct No *atual = f->inicio;
        
        while (atual->proximo != NULL && atual->proximo->prioridade >= prio) { // percorre enquanto não chegar no fim e enquanto o próximo for mais importante que o novo
            atual = atual->proximo;
        }
        
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
    printf("Inserido: %d (Prio: %d)\n", val, prio);
}

void remover(struct Fila *f) {
    if (f->inicio == NULL) {
        printf("Fila vazia\n");
        return;
    }
    struct No *aux = f->inicio;
    f->inicio = f->inicio->proximo;
    printf("Removido: %d\n", aux->valor);
    free(aux);
}

void exibir(struct Fila *f) {
    struct No *temp = f->inicio;
    printf("Fila Atual: ");
    while (temp != NULL) {
        printf("[%d][%d] -> ", temp->valor, temp->prioridade);
        temp = temp->proximo;
    }
}






int main() {
    // Write C code here
    struct Fila minhaFila = {NULL};
    inserir(&minhaFila, 1, 5);
    inserir(&minhaFila, 1, 4);
    inserir(&minhaFila, 1, 3);
    inserir(&minhaFila, 1, 2);
    inserir(&minhaFila, 1, 1);
    inserir(&minhaFila, 1, 0);
    inserir(&minhaFila, 1, 6);
    exibir(&minhaFila);
    remover(&minhaFila);
    exibir(&minhaFila);

    return 0;
}
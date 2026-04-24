// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h> // biblioteca para gerenciar memoria (malloc e free)

#define MAX 5

struct No { // cria a estrutura de um "No" (cada elemento da fila)
    int valor; // Espaço para guardar o número
    struct No *proximo; // ponteiro para o próximo elemento da fila
};

struct Fila { // cria a estrutura que controla a fila inteira
    struct No *inicio; // ponteiro que marca quem é o primeiro da fila
    struct No *fim; // ponteiro que marca quem é o último da fila
    int total; // contador para sabermos quantos elementos existem (limite 5)
};

void adicionar(struct Fila *f, int num) { // função para colocar um numero na fila
    if (f->total>=MAX) { // verifica se o contador chegou no limite de 5
        printf("Fila cheia! Não cabe o %d\n", num); 
        return; // sai da função sem adicionar nada (porque nao tem espaço)
    }
    
    struct No *novo = (struct No*) malloc(sizeof(struct No)); // Aloca memória para o novo elemento
    novo->valor = num; // salva o numero dentro desse novo espaço
    novo->proximo = NULL; // como ele é o último, não aponta para ninguem depois dele
    
    if (f->inicio == NULL) { // verifica se a fila estava vazia (primeiro elemento)
        f->inicio = novo; // o novo elemento passa a ser o inicio
        
    } else { // caso a fila já tenha alguém
        f->fim->proximo = novo; // o antigo 'fim' agora aponta para o novo elemento inserido
    } // fim da lógica de conexão
    
    f->fim = novo; // o ponteiro 'fim' agora atualiza para o novo elemento
    f->total++; // aumenta o contador de elementos na fila
    
    printf("Adicionado: %d\n", num); // confirma a adição
} // fim da função de adicionar


void remover(struct Fila *f) { // função para tirar o primeiro da fila
    if (f->inicio == NULL) { // verifica se a fila esta vazia
        printf("Fila vazia!\n"); // não há nada para retirar
        return; // sai da funcao
    }
    
    struct No *aux = f->inicio; // cria um ponteiro auxiliar para segurar o elemento que vai sair
    printf("Removido: %d\n", aux->valor); // mostra o valor que esta sendo removido
    
    f->inicio = f->inicio->proximo; // o inicio da fila passa a ser o segundo elemento
    
    if (f->inicio == NULL) { // se após remover a fila ficou vazia
        f->fim = NULL; // o ponteiro fim também deve ficar nulo
    } // fim da verificação de esvaziamento
    
    free(aux); // libera a memória que o elemento removido estava usando
    f->total--; // diminui o contador de elementos
} // fim da função de remover



int main() {
    struct Fila  minhaFila = {NULL, NULL, 0}; // cria a fila e inicia os ponteiros com NULL e total como 0
    
    adicionar(&minhaFila, 10);
    adicionar(&minhaFila, 20);
    adicionar(&minhaFila, 30);
    adicionar(&minhaFila, 40);
    adicionar(&minhaFila, 50);
    adicionar(&minhaFila, 60);
    
    remover(&minhaFila);
    
    adicionar(&minhaFila, 60);
    
    return 0;
}
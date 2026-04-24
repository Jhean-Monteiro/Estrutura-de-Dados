#include <stdio.h> // Biblioteca para imprimir mensagens (printf)
#include <stdlib.h> // Biblioteca para gerenciar memória (malloc e free)

#define MAX 5 // Define o limite máximo da fila como 5

struct No { // Cria a estrutura de um "No" (cada elemento da fila)
    int valor; // Espaço para guardar o número
    struct No *proximo; // Ponteiro que "aponta" para o próximo elemento da fila
}; // Fim da definição do Nó

struct Fila { // Cria a estrutura que controla a fila inteira
    struct No *inicio; // Ponteiro que marca quem é o primeiro da fila
    struct No *fim; // Ponteiro que marca quem é o último da fila
    int total; // Contador para sabermos quantos elementos existem (limite 5)
}; // Fim da definição da Fila

void adicionar(struct Fila *f, int num) { // Função para colocar um número na fila
    if (f->total >= MAX) { // Verifica se o contador chegou no limite de 5
        printf("Fila cheia! Nao cabe o %d\n", num); // Avisa que lotou
        return; // Sai da função sem adicionar nada
    } // Fim da verificação de fila cheia
    
    struct No *novo = (struct No*) malloc(sizeof(struct No)); // Aloca memória para o novo elemento
    novo->valor = num; // Salva o número dentro desse novo espaço
    novo->proximo = NULL; // Como ele é o último, não aponta para ninguém depois dele
    
    if (f->inicio == NULL) { // Verifica se a fila estava vazia (primeiro elemento)
        f->inicio = novo; // O novo elemento passa a ser o início
    } else { // Caso a fila já tenha alguém
        f->fim->proximo = novo; // O antigo "fim" agora aponta para este novo elemento
    } // Fim da lógica de conexão
    
    f->fim = novo; // O ponteiro "fim" da fila agora atualiza para o novo elemento
    f->total++; // Aumenta o contador de elementos na fila
    printf("Adicionado: %d\n", num); // Confirma a adição
} // Fim da função adicionar

void remover(struct Fila *f) { // Função para tirar o primeiro da fila
    if (f->inicio == NULL) { // Verifica se a fila está vazia
        printf("Fila vazia!\n"); // Avisa que não tem ninguém para tirar
        return; // Sai da função
    } // Fim da verificação de fila vazia
    
    struct No *aux = f->inicio; // Cria um ponteiro auxiliar para segurar o elemento que vai sair
    printf("Removido: %d\n", aux->valor); // Mostra o valor que está sendo removido
    
    f->inicio = f->inicio->proximo; // O início da fila passa a ser o segundo elemento
    
    if (f->inicio == NULL) { // Se após remover a fila ficou vazia
        f->fim = NULL; // O ponteiro fim também deve ficar nulo
    } // Fim da verificação de esvaziamento
    
    free(aux); // Libera a memória que o elemento removido estava usando
    f->total--; // Diminui o contador de elementos
} // Fim da função remover

int main() { // Função principal onde o programa começa
    struct Fila minhaFila = {NULL, NULL, 0}; // Cria a fila e inicia os ponteiros como NULL e total como 0
    
    adicionar(&minhaFila, 10); // Adiciona o 10
    adicionar(&minhaFila, 20); // Adiciona o 20
    adicionar(&minhaFila, 30); // Adiciona o 30
    adicionar(&minhaFila, 40); // Adiciona o 40
    adicionar(&minhaFila, 50); // Adiciona o 50 (chegou no limite 5)
    adicionar(&minhaFila, 60); // Tenta adicionar o 60, mas vai dar erro de cheia
    
    remover(&minhaFila); // Remove o 10 (o primeiro da fila)
    adicionar(&minhaFila, 60); // Agora o 60 consegue entrar!
    
    return 0; // Finaliza o programa
} // Fim do main
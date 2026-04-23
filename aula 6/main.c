#include <stdio.h>  // Inclui a biblioteca padrão de entrada e saída
#include <stdlib.h> // Inclui malloc() e free() para alocação dinâmica

#define MAX_SIZE 5 // define o tamanho maximo da fila circular


// == Estrutura de um NÓ da fila (lista encadeada) ==
typedef struct No { // define um novo tipo chamado 'No'
    int valor; // campo que armazena o valor inteiro do nó
    struct No* proximo; // ponteiro para o próximo nó da fila (encadeamento)
} No; // Nome do tipo após o typedef


// == Estrutura da FILA CIRCULAR com ponteiros ==
typedef struct { // define um novo tipo anonimo (sem tag)
    No* frente; // ponteiro para o primeiro nó (quem sai primeiro)
    No* tras; // ponteiro para o ultimo nó (quem entrou por ultimo)
    int tamanho; // contador de elementos atuais na fila
} Fila; // nome do tipo: fila


// == inicializa a fila zerando todos os campos ==
void inicializarFila(Fila* f) { // recebe um ponteiro para a fila a ser inicializada
    f->frente = NULL; // fila começa sem nenhum nó na frente
    f->tras = NULL; // fila começa sem nenhum nó atrás
    f->tamanho = 0; // contador de elementos começa em zero
}



// == verifica se a fila está VAZIA ==
int estaVazia(Fila* f) { // recebe ponteiro para a fila
    return f->tamanho == 0; // retorna 1 (verdadeiro) se não há elementos
}

// == verifica se a fila está CHEIA ==
int estaCheia(Fila* f) { // recebe ponteiro para a fila
    return f->tamanho == MAX_SIZE; // retorna 1 (verdadeiro) se atingiu o limite máximo definido
}


// == ENFILEIRAR --- insere um valor no final da fila ==
void enfileirar(Fila* f, int valor) { // recebe a fila e o valor a inserir
    if (estaCheia(f)) { // verifica se ainda há espaco
        printf("Erro: Fila cheia! (limite %d)\n", MAX_SIZE); // exibe erro caso esteja cheio e mostra o limite configurado
        return;
    }
    
    No* novo = (No*) malloc(sizeof(No)); // aluca memória para um novo nó na heap
    
    if (novo == NULL) { // verifica se a alocação foi bem-sucedida
        printf("Erro: Memoria insuficiente."); 
        return; // encerra sem inserir
    }
    
    novo->valor = valor; // armazena o valor recebido dentro do novo nó
    novo->proximo = NULL; // o novo nó ainda não aponta para nenhum próximo
    
    if(estaVazia(f)) { // caso especial: fila estava vazia antes da inserção
        f->frente = novo; // novo nó é simultaneamente frente...
        f->tras = novo; // e trás da fila...
        
    } else { // caso normal: já existem elementos na fila
        f->tras->proximo = novo; // o antigo ultimo nó aponta para o novo
        f->tras = novo; // o ponteiro 'tras' avança para o novo nó
    }
    
    f->tamanho++; // incrementa o contador de elementos
    printf("Enfileirado: %d\n", valor); // confirma a inserção do usuário
}


// == DESENFILEIRAR --- remove e retorna o elemento da frente ==
int desenfileirar(Fila* f) { // recebe o ponteiro para a fila
    if (estaVazia(f)) { // verifica se há algo para remover
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    
    No* temp = f->frente; // Guarda referência ao nó que será removido
    int valor = temp->valor; // salva o valor antes de liberar a memória
    
    f->frente = f->frente->proximo; // avança a frente para o próximo nó
    
    if(f->frente == NULL) { // se a frente virou NULL, a fila esvaziou
        f->tras = NULL; // "tras" tambem deve apontar para NULL
    }
    
    free(temp); // libera a memória do nó removido (evita vazamento)
    f->tamanho--; // decrementa o contador de elementos
    
    return valor;
}


// == Exibe todos os elementos da fila (sem remover) ==
void exibirFila(Fila* f){
    if (estaVazia(f)){ // verifica se existem elementos para exibir
        printf("Fila vazia!\n");
        return; // encerra sem tentar percorrer
    }
    
    printf("Fila (%d/%d): ", f->tamanho, MAX_SIZE); // mostra a quantidade atual e a máxima de elementos na fila
    No* atual = f->frente; // começa pelo primeiro nó
    while (atual != NULL) { // percorre até o fim da cadeia
        printf("%d ", atual->valor); // imprime o valor atual
        atual = atual->proximo; // avança para o próximo nó
    }
    printf("\n");
}


// === Libera toda a memória da fila ao encerrar ===
void liberaFila(Fila* f) {
    while (!estaVazia(f)) { // enquanto ainda houver lementos...
    desenfileirar(f);
    }
}


// == Função principal ---- demonstra uso da fila
int main(){ 
    Fila f; // declara a variavel que representa a fila
    inicializarFila(&f); // inicializa os ponteiros e o contador antes de usar
    
    // ----- Inserções ----- //
    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);
    
    exibirFila(&f); // exibe o estado atual da fila
    
    // --- Remoção --- //
    printf("Desenfileirado: %d\n", desenfileirar(&f));
    exibirFila(&f);
    
    // --- teste de reutilização do espaço (vantagem circular/ponteiro)
    enfileirar(&f, 40); // reutiliza espaço liberado [20, 30, 40]
    enfileirar(&f, 50); // insere mais um [20, 30, 40, 50]
    enfileirar(&f, 60); // insere mais um [20, 30, 40, 50, 60]
    enfileirar(&f, 70); // erro: fila cheia
    
    exibirFila(&f); // exibe Fila completa: [20, 30, 40, 50, 60]
    
    liberaFila(&f); // libera toda a memoria alocada antes de encerrar
    
    return 0; // encerra o programa com sucesso
}
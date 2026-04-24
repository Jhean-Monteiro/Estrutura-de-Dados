#include <stdio.h>

#define MAX_SIZE 5

int fila[MAX_SIZE]; // cria a nossa fila, que é um vetor com 5 espaços
int inicio = -1; // marcador de onde a fila começa (-1 significa que esta vazia)
int fim = -1; // marcador de onde a fila termina (-1 significa que esta vazia)

void adicionar(int valor) { // funcao para colocar um numero novo na fila
    if ((fim + 1) % MAX_SIZE == inicio) { // Circular: se o próximo passo bater no inicio, lotou.
        printf("Fila cheia! Não cabe o valor %d.\n", valor);
    } else { // se ainda tem espaço na fila...
        if (inicio == -1) { // verifica se a fila estava totalmente vazia
            inicio = 0; // se estava, o inicio passa a ser a primeira posicao (0)
        }
        fim = (fim + 1) % MAX_SIZE; // o fim da fila dá um passo (a matemática com '%' faz ele voltar pro 0 se passar do limite)
        fila[fim] = valor; // coloca o número que recebemos na nova posicao do fim
        printf("Adicionado: %d\n", valor); // avisa que o valor entrou com sucesso
    } // fim do bloco de quando tem espaço
} // fim da funcao de adicionar

void remover() { // função para tirar o primeiro da fila
    if (inicio == -1) { //verifica se a fila esta vazia
        printf("Fila vazia! nao tem ninguém pra remover \n");
    } else { // se tem alguém pra tirar
        printf("Removido: %d\n", fila[inicio]); // mostra o valor que esta no inicio e vai sair
        
        if (inicio == fim) { // se o inicio é igual ao fim, significa que só tinha uma pessoa
        inicio = -1; // a fila volta ao estado inicial (vazia)
        fim = -1; // o fim tambem reinicia
        } else { // se tinha mais de uma pessoa na fila
            inicio = (inicio + 1) % MAX_SIZE; // o inicio da um passo, andando de forma circular
        } // fim do bloco que atualiza o inicio
    } // fim do bloco de quando tem alguém para remover
} // fim da funcao de remover


int main() {
    adicionar(1);
    adicionar(2);
    adicionar(3);
    adicionar(4);
    adicionar(5);
    adicionar(6);
    remover();
    adicionar(7);
    return 0;
}

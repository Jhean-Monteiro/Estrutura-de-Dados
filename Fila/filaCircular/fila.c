#include <stdio.h>

#define MAX 50
#define MAX_CIRCULAR 5

typedef struct {
    char nome[MAX];
    int idade;
    int gravidade;
    int tipo;
} Paciente;

Paciente fc[MAX_CIRCULAR];
int frente = -1;
int tras = -1;

int fc_vazia();

int fc_cheia ();

void fc_enfileirar(Paciente paciente);

void fc_exibir();

Paciente fc_desenfileirar();



int main() {
    Paciente p = {"Jhean", 20, 5, 2};
    Paciente q = {"asas", 20, 5, 2};
    Paciente a = {"Jhsdsdean", 20, 5, 2};
    Paciente v = {"dfdfdf", 20, 5, 2};
    Paciente o = {"ngfg", 20, 5, 2};
    Paciente i = {"123445", 20, 5, 2};
    fc_enfileirar(p);
    fc_enfileirar(q);
    fc_enfileirar(a);
    fc_enfileirar(v);
    fc_enfileirar(o);
    fc_enfileirar(i);
    fc_exibir();
    fc_desenfileirar();
    fc_desenfileirar();
    fc_exibir();

    return 0;
}


int fc_vazia(){
    return frente == -1;
}

int fc_cheia (){
    return frente == (tras+1) % MAX_CIRCULAR;
}

void fc_enfileirar(Paciente paciente){
    if(fc_cheia()){
        printf("Fila de exames cheia! removendo o paciente mais antigo%s\n", fc[frente].nome);
        frente = (frente + 1) % MAX_CIRCULAR;
    }
    
    if (fc_vazia()){
        frente = 0;
    }
    tras = (tras+1) % MAX_CIRCULAR;
    fc[tras] = paciente;
    printf("Paciente %s adicionado a fila de exames\n", paciente.nome);
}


Paciente fc_desenfileirar(){
    Paciente vazio = {"", 0, 0, 0};
    if(fc_vazia()){
        printf("Nenhum paciente na fila de exames!");
        return vazio;
    }
    
    Paciente atendido = fc[frente];
    
    printf("Paciente %s foi atendido\n", atendido.nome);
    
    if(frente == tras) { // era o ultimo elemento
        frente = -1;
        tras = -1;
    } else {
        frente = (frente+1) % MAX_CIRCULAR;
    }
    return atendido;
}

void fc_exibir(){
    if (fc_vazia()) {
        printf("Erro: Nenhum paciente para exibir!\n");
        return;
    }
    
    printf("=== EXAMES (primeiro -> ultimo) ===\n");
    
    int i = frente;
    while (i != tras) {
        printf("Nome: %s / Idade: %d / Gravidade: %d\n", fc[i].nome, fc[i].idade, fc[i].gravidade);
        
        i = (i+1) % MAX_CIRCULAR;
    }
    printf("Nome: %s / Idade: %d / Gravidade: %d\n",
        fc[tras].nome, fc[tras].idade, fc[tras].gravidade);
}

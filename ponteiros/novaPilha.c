#include<stdio.h>
#include<stdlib.h>

struct pessoa {
    int senha;
    struct pessoa *prox; // Aponta para a pessoa que está "embaixo" na pilha
};

typedef struct pessoa Pessoa;
Pessoa *topo = NULL;

void push(int senha) {
    Pessoa *novo = 
    (Pessoa *)malloc(sizeof(Pessoa));
    novo->senha = senha;
    novo->prox = topo; 
    topo = novo;
    printf("Pessoa com senha %d colocada no TOPO da pilha.\n", senha);      
}

void pop() {
    if(topo == NULL){
        printf("Pilha vazia!\n");
        return;
    }
    Pessoa *temp = topo;
    topo = topo->prox;
    printf("Pessoa com senha %d removida 
        do TOPO da pilha.\n", temp->senha);
    free(temp);
}

void listar() {
    Pessoa *aux = topo;
    printf("\n--- Status da Pilha 
        (Do TOPO para a BASE) ---\n");
    while (aux != NULL) {
        printf("[Senha: %d]\n", aux->senha);
        aux = aux->prox;
    }
}
int main() {
    push(101);
    push(102);
    push(103);

    pop();
    listar();

    return 0;
}




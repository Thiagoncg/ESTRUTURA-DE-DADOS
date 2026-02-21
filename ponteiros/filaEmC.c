#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para um nó da fila
struct pessoa {
    int senha;
    struct pessoa *prox;
};

typedef struct pessoa Pessoa;

// Ponteiro global para o início da fila
Pessoa *fila = NULL;

// Função para adicionar uma pessoa à fila
void add(int senha) {
    // Aloca memória dinamicamente para nova pessoa.
    Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));
    
    novo->senha = senha;
    novo->prox = NULL;

    // Verifica se a fila está vazia
    if (fila == NULL) {
        fila = novo;
    } else {
        // Caso contrário, percorre a fila até o final e adiciona a nova pessoa
        Pessoa *aux = fila;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    printf("Pessoa com senha %d adicionada à fila.\n", senha);      
}

// Renomeado de 'remove' para 'remover' para evitar conflito com stdio.h
void remover() {
    if (fila == NULL) {  
        printf("A fila está vazia. Não há pessoas para remover.\n");
        return; // Adicionado o ponto e vírgula faltando
    }
    
    Pessoa *temp = fila;
    printf("Atendendo pessoa com senha %d.\n", temp->senha);
    
    fila = fila->prox; // Move o início da fila para o próximo nó
    free(temp);        // Libera a memória do nó removido  
}

void listar() {
    Pessoa *aux = fila;
    printf("Status da fila:\n");
    while (aux != NULL) {
        printf("[Senha: %d] -> ", aux->senha);
        aux = aux->prox;
    }
    printf("Fim...\n");
}

int main() {
    add(125);
    add(235);
    add(396);
    add(125);


    listar();

    remover(); // Atualizado para o novo nome da função

    listar();

    return 0;
}
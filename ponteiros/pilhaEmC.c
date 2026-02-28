#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Necessário para a função strcpy()

// Definição da estrutura para um nó da pilha
struct pessoa {
    int senha;
    char nome[50];
    struct pessoa *prox; // Aponta para a pessoa que está "embaixo" na pilha
};

typedef struct pessoa Pessoa;

// Ponteiro global para o TOPO da pilha
Pessoa *topo = NULL;

// Função para adicionar uma pessoa à pilha (Empilhar / Push)
void push(int senha, const char *nome) {
    // 1. Aloca memória dinamicamente para a nova pessoa
    Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));
    
    // 2. Preenche os dados da nova pessoa
    novo->senha = senha;
    strcpy(novo->nome, nome); // Copia a string recebida para o campo nome da struct
    
    // 3. O "próximo" dessa nova pessoa será o elemento que era o topo antigo
    novo->prox = topo; 

    // 4. O novo topo da pilha passa a ser essa nova pessoa que acabou de entrar
    topo = novo;
    
    printf("Pessoa '%s' com senha %d colocada no TOPO da pilha.\n", novo->nome, senha);      
}

// Função para remover uma pessoa da pilha (Desempilhar / Pop)
void pop() {
    // 1. Verifica se a pilha está vazia
    if (topo == NULL) {  
        printf("A pilha está vazia. Não há pessoas para atender.\n");
        return; 
    }
    
    // 2. Guarda o nó atual do topo em uma variável temporária
    Pessoa *temp = topo;
    
    printf("Atendendo pessoa '%s' com senha %d do TOPO.\n", temp->nome, temp->senha);
    
    // 3. Move o topo para o elemento que estava "embaixo" do atual
    topo = topo->prox; 
    
    // 4. Libera a memória do elemento que foi atendido (removido)
    free(temp);        
}

// Função para listar os elementos da pilha
void listar() {
    Pessoa *aux = topo;
    printf("\n--- Status da Pilha (Do TOPO para a BASE) ---\n");
    
    // Percorre do topo até chegar no fim (NULL)
    while (aux != NULL) {
        printf("[Senha: %d | Nome: %s]\n", aux->senha, aux->nome);
        if (aux->prox != NULL) {
            printf("    |\n");
            printf("    V\n");
        }
        aux = aux->prox;
    }
    printf("--- Fim (Base da Pilha) ---\n\n");
}

int main() {
    // Inserindo elementos na pilha passando Senha e Nome
    push(1, "Ana");    // Entra primeiro, vai ficar na base
    push(2, "Carlos"); // Fica no meio
    push(3, "Beatriz"); // Entra por último, fica no TOPO

    // Mostra a pilha
    listar();

    // Remove o elemento do TOPO (O último que entrou: 3 - Beatriz)
    pop();

    // Mostra a pilha novamente para ver o resultado
    listar();

    return 0;
}
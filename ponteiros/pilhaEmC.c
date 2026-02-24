#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para um nó da pilha
struct pessoa {
    int senha;
    struct pessoa *prox; // Aponta para a pessoa que está "embaixo" na pilha
};

typedef struct pessoa Pessoa;

// Ponteiro global para o TOPO da pilha (substitui o antigo ponteiro 'fila')
Pessoa *topo = NULL;

// Função para adicionar uma pessoa à pilha (Empilhar / Push)
void push(int senha) {
    // 1. Aloca memória dinamicamente para a nova pessoa
    Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));
    
    // 2. Preenche os dados da nova pessoa
    novo->senha = senha;
    
    // 3. O "próximo" dessa nova pessoa será o elemento que era o topo antigo
    // Se a pilha estiver vazia, novo->prox apontará para NULL, o que está correto.
    novo->prox = topo; 

    // 4. O novo topo da pilha passa a ser essa nova pessoa que acabou de entrar
    topo = novo;
    
    printf("Pessoa com senha %d colocada no TOPO da pilha.\n", senha);      
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
    
    printf("Atendendo pessoa com senha %d do TOPO.\n", temp->senha);
    
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
        printf("[Senha: %d]\n", aux->senha);
        if (aux->prox != NULL) {
            printf("    |\n");
            printf("    V\n");
        }
        aux = aux->prox;
    }
    printf("--- Fim (Base da Pilha) ---\n\n");
}

int main() {
    // Inserindo elementos na pilha
    push(1); // Entra primeiro, vai ficar na base
    push(2); // Fica no meio
    push(3); // Entra por último, fica no TOPO

    // Mostra a pilha
    listar();

    // Remove o elemento do TOPO (O último que entrou: 3)
    pop();

    // Mostra a pilha novamente para ver o resultado
    listar();

    return 0;
}
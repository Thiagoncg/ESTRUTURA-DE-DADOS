#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRICAO 50

// Estrutura do nó da fila
struct Pedido {
    int codigo;
    char descricao[MAX_DESCRICAO];
    struct Pedido* proximo;
};

// Estrutura da fila
struct Fila {
    struct Pedido* inicio;
    struct Pedido* fim;
};

// Inicializa a fila
void inicializarFila(struct Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Adiciona um pedido à fila
void adicionarPedido(struct Fila* fila, int codigo, char* descricao) {
    struct Pedido* novo = (struct Pedido*)malloc(sizeof(struct Pedido));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\\n");
        return;
    }
    novo->codigo = codigo;
    strncpy(novo->descricao, descricao, MAX_DESCRICAO);
    novo->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
    printf("Pedido %d adicionado: %s\\n", codigo, descricao);
}

// Remove o pedido mais antigo da fila
void removerPedido(struct Fila* fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia!\\n");
        return;
    }
    struct Pedido* temp = fila->inicio;
    printf("Removendo pedido %d: %s\\n", temp->codigo, temp->descricao);
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(temp);
}

int main() {
    struct Fila fila;
    inicializarFila(&fila);

    adicionarPedido(&fila, 1, "Camiseta");
    adicionarPedido(&fila, 2, "Calça");
    removerPedido(&fila);
    adicionarPedido(&fila, 3, "Sapato");
    removerPedido(&fila);

    return 0;
}

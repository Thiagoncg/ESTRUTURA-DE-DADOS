#include <stdio.h>
#include <stdlib.h> // Necessário para malloc e free

// 1. DEFINIÇÃO DAS ESTRUTURAS

// Representa um nó (um item individual na fila)
typedef struct Elemento {
    int valor;                 // O dado armazenado (ex: Idade) Comandas, senha de filas
    struct Elemento *proximo;  // Ponteiro para o próximo elemento da fila
} Elemento;

// Representa a Fila em si (o controlador)
typedef struct {
    Elemento *inicio; // Ponteiro para a cabeça da fila (quem vai sair)
    Elemento *fim;    // Ponteiro para a cauda da fila (onde novos entram)
} Fila;

// 2. FUNÇÕES DE MANIPULAÇÃO

// Função para iniciar a fila (garante que os ponteiros comecem nulos)
void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

// Função para inserir um item (Enqueue)
// Recebe o ponteiro da fila e o valor a ser adicionado
void enfileirar(Fila *f, int numero) {
    // Aloca memória para o novo elemento dinamicamente
    Elemento *novoElemento = (Elemento*) malloc(sizeof(Elemento));
    
    // Configura o novo elemento
    novoElemento->valor = numero;
    novoElemento->proximo = NULL; // Ele será o último, então não aponta para ninguém

    // Verifica se a fila está vazia
    if (f->inicio == NULL) {
        // Se vazia, o novo elemento é tanto o início quanto o fim
        f->inicio = novoElemento;
        f->fim = novoElemento;
    } else {
        // Se já tem gente, o atual último aponta para o novo
        f->fim->proximo = novoElemento;
        // Atualizamos o ponteiro de fim para ser o novo elemento
        f->fim = novoElemento;
    }
    printf("Inserido: %d\n", numero);
}

// Função para remover um item (Dequeue)
int desenfileirar(Fila *f) {
    // Verifica se a fila está vazia antes de tentar remover
    if (f->inicio == NULL) {
        printf("Fila vazia! Nao ha nada para remover.\n");
        return -1; // Retorna erro
    }

    // Cria um ponteiro temporário para não perdermos a referência do item a ser removido
    Elemento *itemParaRemover = f->inicio;
    int valorSalvo = itemParaRemover->valor; // Guarda o valor para retornar ao usuário

    // O início da fila passa a ser o segundo da fila (o próximo do atual início)
    f->inicio = f->inicio->proximo;

    // Se a fila ficou vazia após a remoção, o fim também deve ser NULL
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    // Libera a memória do item removido (muito importante em C!)
    free(itemParaRemover);

    return valorSalvo;
}

// Função para mostrar a fila atual
void imprimirFila(Fila *f) {
    if (f->inicio == NULL) {
        printf("Fila Vazia.\n");
        return;
    }

    Elemento *atual = f->inicio;
    printf("Inicio -> ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo; // Caminha para o próximo
    }
    printf("-> Fim\n");
}

// 3. PROGRAMA PRINCIPAL (MAIN)

int main() {
    Fila minhaFila;
    
    // Passo 1: Preparar a fila
    inicializarFila(&minhaFila);

    printf("--- Adicionando elementos ---\n");
    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    enfileirar(&minhaFila, 30);

    printf("\n--- Estado Atual ---\n");
    imprimirFila(&minhaFila);

    printf("\n--- Removendo elementos ---\n");
    int removido = desenfileirar(&minhaFila);
    printf("Removemos o valor: %d\n", removido);

    printf("\n--- Estado Apos Remocao ---\n");
    imprimirFila(&minhaFila);

    printf("\n--- Adicionando mais um ---\n");
    enfileirar(&minhaFila, 50);
    imprimirFila(&minhaFila);

    return 0;
}
#include <stdio.h>

#define MAX_PESSOAS 5

// Para simplificar o manuseio vamos usar uma lista
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa pessoas[MAX_PESSOAS];
    int i;

    // for para entrar com os dados das pessoas
    printf("Cadastro de %d pessoas \n", MAX_PESSOAS);
    for (i = 0; i < MAX_PESSOAS; i++) {
        printf("\n Pessoa %d: \n ", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", pessoas[i].nome); // Lê string com espaços
        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
        printf("Altura (em metros): ");
        scanf("%f", &pessoas[i].altura);
    }

    // For com o objetivo de verificar a saida das pessoas
    printf("\nResultado:\n");
    for (i = 0; i < MAX_PESSOAS; i++) {
        printf("\n%s, %d anos, %.2f m - ", pessoas[i].nome, pessoas[i].idade, pessoas[i].altura);
        
        if (pessoas[i].idade > 12 && pessoas[i].altura > 1.20) {
            printf("PODE andar no brinquedo.\n");
        } else {
            printf("NÃO PODE andar no brinquedo.\n");
        }
    }

    return 0;
}

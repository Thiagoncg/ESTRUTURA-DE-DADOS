#include <stdio.h>
#include <stdlib.h>

//Exercício - precisamos alocar uma quantidade grande de pontos que não sabemos de antemão.
//Latitute e longitude de um carro no globo
struct ponto
{
    float latitude;
    float longitude;
};

typedef struct ponto Ponto;

int main() {
    //Ponto *p = ponteiro esta apontando dinamicamente para uma estrutura do tipo ponto
    //Função malloc - aloca dinamicamnete um espaço em memória - alocada na memoria RIP - memória rip
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));
    p->latitude = 1;
    p->longitude = 5;

    printf("Ponto doc carrinho = (%f, %f)", p->latitude, p->longitude);

    return 0;
}
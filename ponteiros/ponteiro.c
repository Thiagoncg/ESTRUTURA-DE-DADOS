#include <stdio.h>




int *ponteiro;//Acabei de criar um ponteiro Int chamado de ponteiro
int val = 5;

int main() {
    //& significa Endereço - neste caso endereço de val (&val)
    ponteiro = &val; // ponteiro esta apontando para o endereço onde está a variavel 'val'
    printf("O valor apontado por 'ponteiro' é ?: %d", *ponteiro);// Acessar o valor da variavel val por meio do ponteiro
    return 0;
}
//Sim eu sei não faz nenhum sentido, eu posso simplesmente acessar diretamente a variável val, já que eu já tenho
//o valor de Val.
//Então porque essa enhaca toda!
//Esta valor já esta sendo alocado no início do programa, mas quando eu precisar de informaçõe dinamicamente.
//ou seja em tempo de execução sob demanda, (quando eu não sei a quantidade de informações que eu vou alocar.)
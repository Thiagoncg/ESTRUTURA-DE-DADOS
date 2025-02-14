#include <stdio.h>

struct pessoa
{
	int idade;
	float altura;
};

//Redefine tipo de dados - renomenado pessoa para Pessoa
typedef struct pessoa Pessoa;

int main() {

	Pessoa p;
	p.idade = 5;
	p.altura = 1.65;

	printf("A idade da pessoa é: %d",
	p.idade);

	printf("\nA altura da pessoa é: %.2f",
	p.altura);

  	return 0;
}
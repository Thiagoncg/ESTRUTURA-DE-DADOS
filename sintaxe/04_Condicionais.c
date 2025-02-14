#include <stdio.h>

int main() {

	int a;
	printf("Digite um número: ");
	scanf("%d",&a);

	// == comparação de igualdade
	// >  comparação de maior
	// <  comparação de menor
	// >= comparação de maior ou igual
	// <= comparação de menor ou igual
	// != comparação de diferença

	if(a!=0)
	{
		printf("A variável 'a' é diferente de 0");
	}
	else
	{
		printf("A variável 'a' é 0");
	}



  	return 0;
}
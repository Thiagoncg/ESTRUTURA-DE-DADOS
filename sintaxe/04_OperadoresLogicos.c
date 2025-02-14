#include <stdio.h>

int main() {
  	
	int a, b, c;

	printf("Digite um número: ");
	scanf("%d",&a);
	printf("Digite um número: ");
	scanf("%d",&b);
	printf("Digite um número: ");
	scanf("%d",&c);

	// && operador lógico E
	// || operador lógico OU
	// !  operador lógico NÃO

	if(a==b && b==c)
	{
		printf("a, b, c tem valores iguais");
	}

  	return 0;
}
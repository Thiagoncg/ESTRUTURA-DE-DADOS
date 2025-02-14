#include <stdio.h>

int main() {

	printf("\nLaço WHILE\n");

	int a=0;

	while(a<5)
	{
		printf("\nVariável 'a' é: %d",a);
		a++;
	}

	printf("\n\nLaço FOR\n");

	// for ( inicialização ; teste ; incremento )
	for(int i=0 ; i<7 ; i+=2)
	{
		printf("\nA variável 'i' é: %d",i);
	}

	return 0;
}
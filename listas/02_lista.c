#include <stdio.h>
#include <stdlib.h>

struct localizacao
{
	float latitude;
	float longitude;
	struct localizacao *prox;
};

typedef struct localizacao Localizacao;

Localizacao *listaLocalizacaos;

void add(float latitude, float longitude)
{
	Localizacao *p = (Localizacao*) malloc(sizeof(Localizacao));
	p->latitude = latitude;
	p->longitude = longitude;
	p->prox = listaLocalizacaos;
	listaLocalizacaos = p;
}

int main() {
	
	add(1,5);
	add(2,7);
	add(5,3);

	printf("%.0f",listaLocalizacaos->latitude);
	printf("%.0f",listaLocalizacaos->prox->latitude);
	printf("%.0f",listaLocalizacaos->prox->prox->latitude);

	printf("%.0f",listaLocalizacaos->longitude);
	printf("%.0f",listaLocalizacaos->prox->longitude);
	printf("%.0f",listaLocalizacaos->prox->prox->longitude);

  	return 0;
}
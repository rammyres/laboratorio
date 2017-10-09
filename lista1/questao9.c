#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "portuguese");
	float cigarros, carteira, anos;

	printf("Há quantos anos você fuma?\n");
	scanf("%f", &anos);
	printf("Quantos cigarros você costuma fumar ao dia?\n");
	scanf("%f", &cigarros);
	printf("Qual o preço médio da carteira?\n");
	scanf("%f", &carteira);

	printf("Você já gastou %.2f neste período\n", (cigarros/20)*carteira*anos*365);

	return 0;
}
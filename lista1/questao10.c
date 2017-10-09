#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "portuguese");
	float a, b, x;

	printf("O objetivo deste programa é calcular a equação de primeiro grau ax+b=0\n");
	printf("Digite o coeficiente a ");
	scanf("%f", &a);
	printf("Digite o coeficiente b ");
	scanf("%f", &b);
	x = (b*-1)/a;

	printf("x = %.2f\n", x);

	return 0;
}
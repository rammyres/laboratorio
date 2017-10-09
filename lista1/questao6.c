#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "portuguese");
	int n;

	printf("Digite um número intero, calcularemos a sobra de sua divisão por 2: ");
	scanf("%d", &n);
	printf("%d\n", n%2);

	return 0;
}
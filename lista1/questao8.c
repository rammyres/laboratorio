#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "portuguese");
	int numero;

	printf("Digite um número, exibiremos seu sucessor e seu antecessor: ");
	scanf("%d", &numero);
	printf("Antecessor: %d\nSucessor: %d\n", numero+1, numero-1);

	return 0;
}
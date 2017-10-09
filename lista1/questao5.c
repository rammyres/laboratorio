#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "portuguese");
	int idade;

	printf("Digite sua idade, somaremos ela com 10: ");
	scanf("%d", &idade);

	printf("%d\n", idade+10);

	return 0;
}
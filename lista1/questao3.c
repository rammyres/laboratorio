#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "portuguese");
	int n;
	printf("Digite um número: ");
	scanf("%d", &n);
	printf("O número digitado foi %d\n", n);

	return 0;
}
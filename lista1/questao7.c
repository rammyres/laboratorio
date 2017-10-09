#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void){
	setlocale(LC_ALL, "portuguese");
	int i;
	char nome[40], sobrenome[40];

	printf("Digite seu nome: ");
	fgets(nome, sizeof(nome), stdin);
	printf("Digite seu sobrenome: ");
	fgets(sobrenome, sizeof(sobrenome), stdin);

	for(i=0; i<=sizeof(nome); i++){
		if(nome[i]=='\n')
			nome[i]='\0';
	}

	printf("Olá %s %s\n", nome, sobrenome);

	return 0;
}

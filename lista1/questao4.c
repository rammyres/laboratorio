#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "portuguese");
	float nota1, nota2, nota3;

	printf("Digite, sequencialmente, as 3 notas de um aluno, iremos retornar a média:");
	scanf("%f", &nota1);
	scanf("%f", &nota2);
	scanf("%f", &nota3);
	printf("A média foi %.2f\n", (nota1+nota2+nota3)/3);

	return 0;
}
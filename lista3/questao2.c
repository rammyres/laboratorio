#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    int i;
    float vetor[10], menor;

    printf("Digite as 10 posi��es de um vetor, retornaremos o menor\n");

    for(i=0; i<10; i++){
        printf("Digite a %d� posi��o: ", i+1);
        scanf("%f", &vetor[i]);
    }

    menor = vetor[9];

    for(i=0; i<10; i++){
        if(menor>vetor[i])
            menor = vetor[i];
    }

    printf("O menor n�mero no vetor � %.2f\n", menor);

    return 0;
}

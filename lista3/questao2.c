#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    int i;
    float vetor[10], menor;

    printf("Digite as 10 posições de um vetor, retornaremos o menor\n");

    for(i=0; i<10; i++){
        printf("Digite a %dª posição: ", i+1);
        scanf("%f", &vetor[i]);
    }

    menor = vetor[9];

    for(i=0; i<10; i++){
        if(menor>vetor[i])
            menor = vetor[i];
    }

    printf("O menor número no vetor é %.2f\n", menor);

    return 0;
}

#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    int i, entrada, vetor[10], tst=0;


    printf("Digite as 10 posições de um vetor, eles serão guardados na memória. \n");

    for(i=0; i<10; i++){
        printf("Digite a %dª posição: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("Agora informe um dos valores, retornaremos a posição em que ele se encontra: ");
    scanf("%d", &entrada);

    for(i=0; i<10; i++){
        if(vetor[i]==entrada)
            printf("O valor digitado está na %dª posição \n", i+1);
            tst++;
        }
    if(tst!=1)
        printf("Número não encontrado\n");

    return 0;
}

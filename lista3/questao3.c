#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    int i, vetor[10];

    printf("Digite as 10 posi��es de um vetor, imprimiremos somente os impares \n");

    for(i=0; i<10; i++){
        printf("Digite a %d� posi��o: ", i+1);
        scanf("%d", &vetor[i]);
    }


    for(i=0; i<10; i++){
        if(vetor[i]%2==1)
            printf("%d ", vetor[i]);
    }

    return 0;
}

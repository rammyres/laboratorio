#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    int i, entrada, vetor[10], tst=0;


    printf("Digite as 10 posi��es de um vetor, eles ser�o guardados na mem�ria. \n");

    for(i=0; i<10; i++){
        printf("Digite a %d� posi��o: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("Agora informe um dos valores, retornaremos a posi��o em que ele se encontra: ");
    scanf("%d", &entrada);

    for(i=0; i<10; i++){
        if(vetor[i]==entrada)
            printf("O valor digitado est� na %d� posi��o \n", i+1);
            tst++;
        }
    if(tst!=1)
        printf("N�mero n�o encontrado\n");

    return 0;
}

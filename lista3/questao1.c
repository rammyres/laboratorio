#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    int i;
    float numeros[11];

    printf("Digite as posi��es do array abaixo, retornaremos sua m�dia:\n");
    for(i=0; i<10; i++){
        printf("%d� posi��o: ", i+1);
        scanf("%f", &
              numeros[i]);
    }

    for(i=0; i<10; i++){
        numeros[10]+=numeros[i];
    }

    printf("A m�dia dos numeros digitados � %f\n", numeros[10]/10);

    return 0;
}

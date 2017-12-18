#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    int i;
    float numeros[11];

    printf("Digite as posições do array abaixo, retornaremos sua média:\n");
    for(i=0; i<10; i++){
        printf("%dª posição: ", i+1);
        scanf("%f", &
              numeros[i]);
    }

    for(i=0; i<10; i++){
        numeros[10]+=numeros[i];
    }

    printf("A média dos numeros digitados é %f\n", numeros[10]/10);

    return 0;
}

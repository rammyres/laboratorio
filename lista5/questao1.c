#include <stdio.h>
#include <locale.h>

float sub(float Na, float Nb){
    return Na-Nb;
}

int main(void){
    setlocale(LC_ALL, "portuguese");
    float a, b;
    printf("Digite dois n�meros, mostraremos sua subtra��o: \n");
    printf("Entre com o primeiro n�mero: ");
    scanf("%f", &a);
    printf("Digite o segundo n�mero: ");
    scanf("%f", &b);
    printf("%+.2f - %+.2f = %+.2f", a, b, sub(a,b));

    return 0;
}

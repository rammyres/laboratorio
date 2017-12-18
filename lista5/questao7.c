#include <stdio.h>
#include <locale.h>

typedef enum { false, true } bool;

bool ehPrimo(int num){
    int i;
    bool resultado=true;

    for(i=num/2; i>1; i--){
        if(num%i==0){
            resultado = false;
            break;
        }
    }
    return resultado;
}

int main(void){
    setlocale(LC_ALL, "portuguese");

    int numero;

    printf("Digite um número, verificaremos se ele é primo: ");
    fflush(stdin);
    scanf("%d", &numero);

    if(numero>1){
        if(ehPrimo(numero)==true){
            printf("O número %d é primo\n", numero);
        } else {
            printf("O número %d não é primo\n", numero);
        }
    } else if(numero==1){
        printf("O número 1, por definição, não é primo ");
    }
    return 0;
}

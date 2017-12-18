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

    printf("Digite um n�mero, verificaremos se ele � primo: ");
    fflush(stdin);
    scanf("%d", &numero);

    if(numero>1){
        if(ehPrimo(numero)==true){
            printf("O n�mero %d � primo\n", numero);
        } else {
            printf("O n�mero %d n�o � primo\n", numero);
        }
    } else if(numero==1){
        printf("O n�mero 1, por defini��o, n�o � primo ");
    }
    return 0;
}

#include <stdio.h>
#include <locale.h>

void ordena(int* a, int* b, int* c){
    int tmp;
    if(*a>*c){
        tmp = *a;
        *a = *c;
        *c = tmp;
    }
    if(*a>*b){
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
    if(*b>*c){
        tmp = *b;
        *b = *c;
        *c = tmp;
    }
}

int main(void){
    setlocale(LC_ALL, "portuguese");
    int Na, Nb, Nc;

    printf("O objetivo desde programa � demonstrar o uso de refer�ncia em fun��o\n");
    printf("Digite tr�s inteiros, colocaremos eles em ordem\n");
    printf("Digite o primeiro n�mero: ");
    scanf("%d", &Na);
    printf("Digite o segundo n�mero: ");
    scanf("%d", &Nb);
    printf("Digite o terceiro n�mero: ");
    scanf("%d", &Nc);
    printf("Numeros originais: %d, %d, %d\n", Na, Nb, Nc);

    ordena(&Na, &Nb, &Nc);

    printf("Numeros ordenados: %d, %d, %d\n", Na, Nb, Nc);

    return 0;
}

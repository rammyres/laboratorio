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

    printf("O objetivo desde programa é demonstrar o uso de referência em função\n");
    printf("Digite três inteiros, colocaremos eles em ordem\n");
    printf("Digite o primeiro número: ");
    scanf("%d", &Na);
    printf("Digite o segundo número: ");
    scanf("%d", &Nb);
    printf("Digite o terceiro número: ");
    scanf("%d", &Nc);
    printf("Numeros originais: %d, %d, %d\n", Na, Nb, Nc);

    ordena(&Na, &Nb, &Nc);

    printf("Numeros ordenados: %d, %d, %d\n", Na, Nb, Nc);

    return 0;
}

#include <stdio.h>
#include <locale.h>

void troca(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

int main(void){
    setlocale(LC_ALL, "portuguese");
    int Na, Nb;

    printf("O objetivo desde programa � demonstrar o uso de refer�ncia em fun��o\n");
    printf("Digite dois inteiros, trocaremos os valores\n");
    printf("Digite o primeiro n�mero: ");
    scanf("%d", &Na);
    printf("Digite o segundo n�mero: ");
    scanf("%d", &Nb);

    printf("Numeros originais: %d e %d\n", Na, Nb);

    troca(&Na, &Nb);

    printf("Numeros trocados: %d e %d\n", Na, Nb);

    return 0;
}

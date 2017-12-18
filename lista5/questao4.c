#include <stdio.h>
#include <locale.h>

int menor(int a, int b, int c){
    int tmp;
    if(a>c){
        tmp = a;
        a = c;
        c = tmp;
    }

    if(a>b){
        tmp = a;
        a = b;
        b = tmp;
    }

    if(b>c){
        tmp = b;
        b = c;
        c = tmp;
    }

    return a;
}

int main(void){
    setlocale(LC_ALL, "portuguese");
    int a, b, c;
    printf("Digite 3 números inteiros, retornaremos o menor: \n");
    printf("Digite o primeiro: ");
    scanf("%d", &a);
    printf("Digite o segundo: ");
    scanf("%d", &b);
    printf("Digite o terceiro: ");
    scanf("%d", &c);

    printf("O menor é %d\n", menor(a, b, c));

    return 0;
}

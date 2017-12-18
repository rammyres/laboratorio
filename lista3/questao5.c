#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    char nome[100], sobrenome[100];
    int i;

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    for(i=0; i<100; i++)
        if(nome[i]=='\n')
            nome[i]='\0';

    printf("Digite seu sobrenome: ");
    fgets(sobrenome, sizeof(sobrenome), stdin);

    printf("Oi %s %s", nome, sobrenome);

    return 0;
}

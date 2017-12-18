#include <stdio.h>
#include <locale.h>

void bomdia(char nome[]){
    printf("Bom dia %s", nome);
}

int main(void){
    setlocale(LC_ALL, "portuguese");

    char nom[40];

    printf("Olá, qual seu nome? ");
    fflush(stdin);
    fgets(nom, sizeof(nom), stdin);
    bomdia(nom);

    return 0;
}

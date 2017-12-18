#include <stdio.h>
#include <locale.h>
#include <ctype.h>

char* pmaiuscula(char ent[20]){
    int i;

    while(ent[i]){
        printf("%c\n", ent[i]);
        ent[i]=toupper(ent[i]);
        printf("%c\n", ent[i]);
    }

    return ent;
}

int main(void){
    setlocale(LC_ALL, "portuguese");

    char entrada[20];

    printf("Digite uma palavra, retornaremos ela com todas as letras maiusculas: ");
    fflush(stdin);
    fgets(entrada, sizeof(entrada), stdin);

    printf("Entrada %s\nSaída %s\n", entrada, pmaiuscula(entrada));

    return 0;
}

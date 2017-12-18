#include <stdio.h>
#include <locale.h>
#include <string.h>

int conta_consoantes(char ent[20]){
    int i, cont=strlen(ent);

    for(i=0; i<strlen(ent); i++){
        switch(ent[i]){
            case 'a' : cont--;
                    break;
            case 'A' : cont--;
                    break;
            case 'e' : cont--;
                    break;
            case 'E' : cont--;
                    break;
            case 'i' : cont--;
                    break;
            case 'I' : cont--;
                    break;
            case 'o' : cont--;
                    break;
            case 'O' : cont--;
                    break;
            case 'u' : cont--;
                    break;
            case 'U' : cont--;
                    break;
        }
    }
    return cont;
}

int main(void){
    setlocale(LC_ALL, "portuguese");
    char entrada[20];
    int i;
    printf("Digite uma palavra, contaremos quantas consoante ela tem (não digite pontos, virgulas, simbolos ou números: ");
    fflush(stdin);
    fgets(entrada, sizeof(entrada), stdin);

    for(i = 0; i<20; i++){
        if(entrada[i]=='\n')
            entrada[i]='\0';
    }

    printf("A palavra \"%s\" possui %d consoantes\n", entrada, conta_consoantes(entrada));

    return 0;
}

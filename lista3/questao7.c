#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    char str1[40], str2[40];
    int i;
    printf("Digite dois textos separados abaixo, eles serão concatenados e seus caracteres contados\n");

    printf("Digite a primeira palavra: ");
    fgets(str1, sizeof(str1), stdin);

    for(i = 1; i<sizeof(str1); i++){
        if( str1[i]=='\n' )
            str1[i]='\0';
    }

    printf("Digite a segunda palavra: ");
    fgets(str2, sizeof(str2), stdin);

    for(i = 1; i<sizeof(str2); i++){
        if( str2[i]=='\n' )
            str2[i]='\0';
    }

    char *strc = (char *)malloc(strlen(str1)+strlen(str2)+1);
    strncpy( strc, str1, sizeof(str1));
    strncat(strc, str2, sizeof(str2));

    printf("O texto digitado foi %s, com %d caracteres\n", strc, strlen(strc));

    return 0;

}

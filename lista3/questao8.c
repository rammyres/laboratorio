#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    char str1[40], str2[40], tmp[40];
    int i;
    printf("Digite dois textos separados abaixo, elas serão trocadas entre as variáveis\n");

    printf("Digite a primeira palavra: ");
    fgets(str1, sizeof(str1), stdin);

    for(i = 1; i<sizeof(str1); i++){
        if( str1[i]=='\n' )
            str1[i]='\0';
    }

    printf("Digite a segunda palavra: ");
    fgets(str2, sizeof(str2), stdin);

    for(i = 1; i<sizeof(str2); i++){
        if( str2[i]=='\n')
            str2[i]='\0';
    }

    printf("Texto original:\nString 1 %s \nString 2: %s\n", str1, str2);
    strncpy(tmp, str2, sizeof(str2));
    strncpy(str2, str1, sizeof(str1));
    strncpy(str1, tmp, sizeof(tmp));

    printf("Texto invertido:\nString 1 %s \nString 2: %s\n", str1, str2);

    return 0;

}

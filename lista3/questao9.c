#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    int i, j, soma=0, matriz[3][3];
    printf("Digite os elementos da matriz 3x3 abaixo: \n");

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Linha %d Coluna %d ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i=0; i<3; i++){
        printf("|");
        for(j=0; j<3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("|\n");
    }
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            soma=soma+matriz[i][j];
        }
    }
    printf("A soma da matriz acima é %d", soma);

    return 0;
}

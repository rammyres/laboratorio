#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    int i, j, eIdentidade=0, matriz[4][4];
    printf("Digite os elementos da matriz 4x4 abaixo: \n");

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            printf("Linha %d Coluna %d ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i=0; i<4; i++){
        printf("|");
        for(j=0; j<4; j++){
            printf("%4d ", matriz[i][j]);
        }
        printf("|\n");
    }
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(i==j)
                if(matriz[i][j]==matriz[i-1][j-1])
                    eIdentidade++;
        }
    }
    if(eIdentidade==3)
        printf("Trata-se de uma matriz identidade\n");
    else
        printf("Não se trata de uma matriz identidade");

    return 0;
}


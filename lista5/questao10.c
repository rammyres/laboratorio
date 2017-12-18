#include <stdio.h>
#include <locale.h>

void torres(int num, char torre_orig, char torre_dest, char torre_aux){

    if (num == 1)
    {
        printf("\n Movendo disco 1 da torre %c para a torre %c", torre_orig, torre_dest);
        return;
    }
    torres(num - 1, torre_orig, torre_aux, torre_dest);
    printf("\n Movendo disco %d da torre %c para a torre %c", num, torre_orig, torre_dest);
    torres(num - 1, torre_aux, torre_dest, torre_orig);
}

int main(void){
    setlocale(LC_ALL, "portuguese");

    int n;

    printf("o objetivo deste programa � resolver o problema matem�tico cl�ssico conhecido como \"Torres de Hanoi\"");
    printf("As rigor, diz a lenda que em Han�i (capital do Vietn�) existem 3 torres contendo\n");
    printf("discos de tamanho diferentes, onde os menores n�o pode ficar sob os maiores e os\n");
    printf("s�bios eram desafiados a mudar os discos de torres, na menor quantidade de movi-\n");
    printf("mentos poss�veis.\n");
    printf("Informe a quantidade de discos que ser�o movimentados: ");
    scanf("%d",&n);
    printf("Movendo os discos: \n");
    torres(n, 'A', 'B', 'C');
    return 0;
}

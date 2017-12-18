#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void){
    setlocale(LC_ALL, "portuguese");
    char str[100], temp;
    int i, j = 0;

    printf("Digite uma palavra, nós a inverteremos: ");
    fgets(str, sizeof(str), stdin);

   i = 0;
   j = strlen(str) - 1;

    while (i < j) {
       temp = str[i];
       str[i] = str[j];
       str[j] = temp;
       i++;
       j--;
   }

    printf("%s", str);

    return 0;
}

#include <stdio.h>
#include <locale.h>

float area(float raio);
float comprimento(float raio);


int main(void){
    setlocale(LC_ALL, "portuguese");
    float ent_raio;

    printf("Digite o raio de um circulo, retornaremos sua área e seu comprimento: ");
    scanf("%f", &ent_raio);
    printf("A área do circulo é de %.2f e seu comprimento é %.2f\n", area(ent_raio), comprimento(ent_raio));

    return 0;
}

float area(float raio){
    float ar = 2*3.1415*(raio*raio);

    return ar;
}

float comprimento(float raio){
    float ra = 2*3.1415*raio;

    return ra;
}

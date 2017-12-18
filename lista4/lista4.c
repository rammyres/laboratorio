#include <stdio.h>
#include <string.h>
#include <locale.h> // Permite o uso da fun��o setlocale, que altera os caracteres de sa�da, evitando erros de acentua��o.

typedef struct data {
    int dia, mes, ano;
} data;

typedef struct funcionarios {
    int matricula;
    char nome[40], estadocivil[10], cargo[20];
    float salario;
    data nascimento;
} funcionarios;

funcionarios inclui_funcionario(void){
    funcionarios func;
    int i;

    printf("Digite a matr�cula do funcionario: ");
    scanf("%d", &func.matricula);

    printf("Digite o nome do funcionario: ");
    fflush(stdin);
    fgets(func.nome, sizeof(func.nome), stdin);
    for(i=0; i<sizeof(func.nome); i++){
        if(func.nome[i]=='\n')
            func.nome[i]='\0';
    }

    printf("Digite o estado civil do funcion�rio: ");
    fflush(stdin);
    fgets(func.estadocivil, sizeof(func.estadocivil), stdin);
    for(i=0; i<sizeof(func.estadocivil); i++){
        if(func.estadocivil[i]=='\n')
            func.estadocivil[i]='\0';
    }

    printf("Digite o cargo do funcion�rio: ");
    fflush(stdin);
    fgets(func.cargo, sizeof(func.cargo), stdin);
    for(i=0; i<sizeof(func.cargo); i++){
        if(func.cargo[i]=='\n')
            func.cargo[i]='\0';
    }

    printf("Digite o sal�rio do funcion�rio: ");
    fflush(stdin);
    scanf("%f", &func.salario);

    printf("Digite agora a data de nascimento: \n");
    printf("Digite o dia: ");
    scanf("%d", &func.nascimento.dia);
    printf("Digite o m�s (janeiro = 01, fevereiro = 02): ");
    scanf("%d", &func.nascimento.mes);
    printf("Digite o ano: ");
    scanf("%d", &func.nascimento.ano);

    return func;
}

int imp_funcionario(funcionarios func){

        printf("Matricula: %d\n", func.matricula);
        printf("Nome: %s\n", func.nome);
        printf("Cargo: %s\n", func.cargo);
        printf("Estado c�vil: %s\n", func.estadocivil);
        printf("Sal�rio: %.2f\n", func.salario);
        printf("Data de nascimento %d/%d/%d\n", func.nascimento.dia, func.nascimento.mes, func.nascimento.ano);
        printf("\n");

        return 0;
}
int imp_funcionarios(funcionarios func[], int num){
    int i;
    for (i=0; i<num; i++){
        printf("Posi��o: %d\n", i+1);
        imp_funcionario(func[i]);
    }
    return 0;
}

int busca_funcionario(funcionarios func[]){
    int i, achado=1;
    char string[40];

    printf("Digite o nome do funcion�rio a ser procurado: ");
    fflush(stdin);
    fgets(string, sizeof(string), stdin);

    for(i=0; i<sizeof(string); i++){
        if(string[i]=='\n')
            string[i]='\0';
    }

    for(i=0; i<=sizeof(func); i++){
        if(strstr(func[i].nome, string)){
            printf("Posi��o %d:\n", i+1);
            imp_funcionario(func[i]);
            achado--;
        }
        else
            achado++;
    }
    if(achado>0)
        printf("Funcion�rio n�o encontrado\n");
}

int menu(void){
    printf("Bem vindo a Lista 4.\nDigite a op��o desejada: \n");
    printf("1 - Cadastrar funcion�rio\n2 - Excluir funcion�rio\n3 - Alterar funcion�rio\n");
    printf("4 - Buscar funcion�rio\n5 - Listar todos os funcion�rios\n6 - Sair\nOp��o: ");

    return 0;
}


int main(void){
    setlocale(LC_ALL, "portuguese");
    funcionarios funcionario[20];
    int entrada, pos, i, fim = -1;
    char nome[40];


    while (entrada!=6) {
            menu();
            scanf("%d", &entrada);

            if (entrada == 1 && fim < 20){
                if(fim<20){
                    printf("Posi��o %d\n", fim+2);
                    funcionario[fim+1]= inclui_funcionario();
                    fim++;
                }
            } else
            if (entrada == 2){
                    char certeza;
                    printf("Informe a posi��o do funcion�rio a ser eliminado: \n");
                    scanf("%d", &pos);
                    if(pos-1 <= fim){
                        imp_funcionario(funcionario[pos-1]);
                        printf("Certeza que deseja eliminar o funcion�rio acima?(s/n) \n");
                        fflush(stdin);
                        scanf("%c", &certeza);
                        if (certeza == 's' || certeza == 'S'){
                            for(i=pos-1; i<fim; i++){
                                funcionario[i] = funcionario [i+1];
                            }
                            fim--;
                        }

                    } else {
                        printf("Imposs�vel excluir. Posi��o Inv�lida.\n");
                    }

            } else
            if (entrada == 3){
                    printf("Informe a posi��o do funcion�rio a ser alterada: ");
                    scanf("%d", &pos);
                    if ( fim >= 0 && pos-1 >= fim ){
                            imp_funcionario(funcionario[pos-1]);
                            printf("Voc� dever� incluir novamente os dados do funcion�rio\n");
                            funcionario[pos-1]=inclui_funcionario();
                    } else {
                        printf("Imposs�vel alterar, posi��o n�o preenchida.\n");
                    }

            } else
            if (entrada == 4){

               busca_funcionario(funcionario);

            } else
            if (entrada == 5){
                if(fim>=0){
                    imp_funcionarios(funcionario, fim+1);
                } else {
                    printf("N�o existem funcion�rios cadastrados\n");
                }

            } else
            if (entrada == 1 && fim >= 19){
                printf("Imposs�vel cadastrar, vetor cheio\n");
            }
    }

    return 0;
}

/*
 * Trabalho final da disciplina Laborat�rios de programa��o, UAB V.
 * Aluno: Rammyres Jos� Oliveira Pereira
 *
 * O programa � um sistema interativo simples, cujo objetivo � criar um registro com dados b�sicos de alunos.
 *
 * O programa utiliza strings para tratamento avan�ado das buscas. Tamb�m utiliza arquivos para armazenamento dos dados dos alunos.
 *
 * A fim de evitar problemas com o arquivamento e apresenta��o de caracteres acentuados, tamb�m usa localiza��o.
 *
 * Pe�o que o respons�vel pela corre��o use o arquivo alunos.ini (incluido no arquivos) como parametro ao chamar o execut�vel (c:\trabfinal alunos.ini ou
 * $ trabfinal alunos.ini) ele cont�m a lista de alunos necess�rios para cumprimento do requisito 'c' da lista.
 *
 */
 #ifdef _WIN32
    #define LIMPAR "cls"
#else
    #define LIMPAR "clear"
#endif // _WIN32

#include <stdio.h>
#include <string.h>
#include <locale.h> // Permite o uso da fun��o setlocale, que altera os caracteres de sa�da, evitando erros de acentua��o.
#include <unistd.h>

//Defini��o da estrututra data
typedef struct data {
    int dia, mes, ano;
} data;

//Defini��o da estrutura disciplinas
typedef struct disciplinas {
    char nome[60], professor[60];
    float nota[3];
} disciplinas;

//Defini��o da estrutura aluno
typedef struct alunos {
    long long matricula;
    char nome[40], endereco[60];
    disciplinas disciplina[3];
    data nascimento;
} alunos;

/* O objetivo desta e das fun��es imp_centralizado e imp_posicao � basicamente est�tico, melhorando a forma como
 * as informa��es s�o mostradas na primeira um loop imprime 80x o simbolo escolhido (largura padr�o de terminais
 * VT100 e 3270).
 * A segunda tem a mesma l�gica, mas imprime uma string no meio da linha e completa os demais espa�os com o
 * caractere escolhidos.
 * A �ltima imprime a posi��o fim em rela��o a quantidade m�xima de registros.
 */
int imp_linha(char c){
        int i;

        for(i=0; i<80; i++)
            printf("%c", c);
        printf("\n");

}

int imp_centralizado(char string[], char c){
    int i, comp=(80-strlen(string))/2;

    if(strlen(string)+2*comp==80)
        for(i=0; i<=comp; i++)
            printf("%c", c);
    else
        for(i=0; i< comp; i++)
            printf("%c", c);

    printf("%s", string);

    if(comp%2>0)
        for(i=0; i<=comp; i++)
            printf("%c", c);
    else
        for(i=0; i<comp; i++)
            printf("%c", c);
    printf("\n");


}

int imp_posicao(int n){
    int i;

    for(i=0; i<56; i++)
        printf("-");
    printf("%2d/20 alunos cadastrados\n", n);
}

/*  Apesar de eu preferir uma abordagem externa, utilizei esta fun��o para coletar de forma interativa os dados cadastrais dos alunos, conforme
 * especificados na documenta��o. A fun��o coleta os dados e retorna como um strunct aluno, que pode ser incluso numa string ou listado diretamente.
 * O parametro da fun��o somente faz a diferencia��o se � inclus�o ou altera��o, para fins est�ticos.
 */

alunos inclui_aluno(int a){
    alunos alun;
    int i, j, k;

    if(a==1){
        imp_linha('=');
        printf("Inclus�o de novo aluno\n");
        imp_linha('-');
    }
    if(a==2){
        imp_linha('=');
        printf("Altera��o de aluno\n");
        imp_linha('-');
    }

    printf("Digite a matr�cula do aluno: ");
    scanf("%d", &alun.matricula);

    printf("Digite o nome do aluno: ");
    fflush(stdin);
    fgets(alun.nome, sizeof(alun.nome), stdin);
    strtok(alun.nome, "\n"); // A fun��o dos diversos strtok (tokenizar strings) � manter somente a por��o anterior ao retorno de carro na string.
                             // Caso os retornos fosse mantidos tanto a apresenta��o dos dados quanto a grava��o e leitura do arquivo de registro
                             // seria comprometida, j� que uma linha nula seria lida como se tivesse dados e criaria um registro com dados aleat�-
                             // rios de mem�ria, o que comprometeria a usabilidade do sistema.

    for(k=0; k<=strlen(alun.nome); k++) // Optei por registrar as strings todas em mais�sculas a fim de facilitar o trabalho do strstr, que faz compara��o
                                        // a partir dos valores ASCCI (portanto inteiros) das letras, dificultando a busca
        alun.nome[k]=toupper(alun.nome[k]);

    printf("Digite o endere�o do aluno: ");
    fflush(stdin);
    fgets(alun.endereco, sizeof(alun.endereco), stdin);
    strtok(alun.endereco, "\n");
    for(k=0; k<=strlen(alun.endereco); k++)
        alun.endereco[k]=toupper(alun.endereco[k]);

    printf("Digite agora a data de nascimento: \n");
    printf("Digite o dia: ");
    scanf("%d", &alun.nascimento.dia);
    printf("Digite o m�s (janeiro = 01, fevereiro = 02): ");
    scanf("%d", &alun.nascimento.mes);
    printf("Digite o ano: ");
    scanf("%d", &alun.nascimento.ano);

    imp_linha('-');

    printf("Digite as disciplinas que o aluno esteja matriculado\n");

    for(i=0; i<3; i++){
        imp_linha('-');
        printf("Digite o nome da %d� disciplina: ", i+1);
        fflush(stdin);
        fgets(alun.disciplina[i].nome, sizeof(alun.disciplina[i].nome), stdin);
        strtok(alun.disciplina[i].nome, "\n");

        for(k=0;k<strlen(alun.disciplina[i].nome); k++)
            alun.disciplina[i].nome[k] = toupper(alun.disciplina[i].nome[k]);


        printf("Digite o nome do professor: ");
        fflush(stdin);
        fgets(alun.disciplina[i].professor, sizeof(alun.disciplina[i].professor), stdin);
        strtok(alun.disciplina[i].professor, "\n");
        for(k=0; k<strlen(alun.disciplina[i].professor); k++)
            alun.disciplina[i].professor[k] = toupper(alun.disciplina[i].professor[k]);

        printf("Digite as notas da disciplina \n");

        for(j = 0; j<3; j++){
            printf("Digite a %d� nota: ", j+1);
            scanf("%f", &alun.disciplina[i].nota[j]);
        }
    }

    return alun;
}
/*
 * Considerando as limita��es das especifica�oes das estruturas aluno e disciplina, n�o � poss�ve registrar nem a m�dia
 * nem o status do aluno diretamente no array, a fun��o, no entanto, facilita a leitura e pode, inclusive, automatizar
 * a busca de alunos aprovados, j� que o retorno � facilmente usado para compara��o
 */
char * status_disciplina(disciplinas disc){
    float media = (disc.nota[0]+disc.nota[1]+disc.nota[2])/3;

    if(media<4)
        return "RN";
    else if(media>=4 && media <7)
        return "EF";
    else if(media>=7)
        return "AM";

}
/*
 * Considerando que a especifi��o do item "j" � levemente diferente da especifica��o dos demais itens,
 * detalhando que somente alguns itens devem ser impressos, ao inv�s da ficha cadastral inteira do aluno
 * optei por cirar uma fun��o especifica, que recebe por parametro o aluno, para coleta dos dados pessoais
 * indicados na quest�o e a disicplina especifica, permitindo a apresenta��o dos dados informados na
 * especifica��o
 */

int imp_dsc(alunos alun, disciplinas dsc){

        imp_linha('=');
        printf("Matricula: %d\n", alun.matricula);
        printf("Nome: %s\n", alun.nome);
        printf("Disciplina: %s\n", dsc.nome);
        printf("Professor: %s\n", dsc.professor);
        printf("Notas: %.2f %.2f %.2f \nM�dia: %.2f\n", dsc.nota[0], dsc.nota[1], dsc.nota[2], (dsc.nota[0]+dsc.nota[1]+dsc.nota[2])/3);
        printf("Status %s\n", status_disciplina(dsc));
        imp_linha('=');
        return 0;
}

/*
 * Conforme especificado no coment�rio acima, h� uma diferen�a entre a impress�o do aluno (usado na maioria das
 * buscas e a especifica de alunos aprovados. Aqui � temos a fun��o usada para a impress�o de todos os dados da ficha
 * cadastral completa do aluno. A fun��o recebe somente um struct aluno como parametro e imprime seus dados no stdin
 */
int imp_aluno(alunos alun){
        int i, j;

        imp_linha('=');
        printf("Matricula: %d\n", alun.matricula);
        printf("Nome: %s\n", alun.nome);
        printf("Endere�o: %s\n", alun.endereco);
        printf("Data de nascimento: %d/%d/%d\n", alun.nascimento.dia, alun.nascimento.mes, alun.nascimento.ano);
        imp_linha('-');
        printf("Disciplinas que o aluno est� matriculado\n");
        for(i=0; i<3; i++){
            imp_linha('-');
            printf("Disciplina %d: %s\n", i+1, alun.disciplina[i].nome);
            printf("Professor: %s\n", alun.disciplina[i].professor);
            printf("Notas: %.2f %.2f %.2f \nM�dia: %.2f\n", alun.disciplina[i].nota[0], alun.disciplina[i].nota[1], alun.disciplina[i].nota[2], (alun.disciplina[i].nota[0]+alun.disciplina[i].nota[1]+alun.disciplina[i].nota[2])/3);
            printf("Status %s\n", status_disciplina(alun.disciplina[i]));
        }
        imp_linha('=');

        return 0;
}

/*
 * Considerando a especifica��o do item "i", optei por automatizar a partir de uma fun��o especifica
 * a listagem de alunos cadastrados, usando como base o array de alunos, diretamente. Como a contagem
 * a partir do array n�o � poss�vel e a abordagem da contagem da mem�ria (memoria alocada/memmoria necessaria
 * para o scruct, que em tese deveria ser um inteiro) � trai�oeira (j� que depende de como o sistema operacional
 * trata alocadores e ponteiros) e o tratamento dessas diferen�as tornariam o programa muito mais complexo
 * optei por receber diretamente pela variavel "fim" a quantidade de alunos existentes
*/

int imp_alunos(alunos aluns[], int num){
    int i;
    for (i=0; i<num; i++){
        printf("Posi��o: %d\n", i+1);
        imp_aluno(aluns[i]);
    }
    return 0;
}


/*
 * As dun��es de busca abaixo tem basicamente a mesma l�gica, comparam a string passada
 * com a vari�vel correspondente  (strstr) num loop for e usam um flag para indicar quando nenhum
 * aluno for localizado. Os dados dos alunos s�o registrados em maisculas em decorr�ncia da limita��o
 * do C que usa char como inteiros (padr�o ASCII), tornando mais dificil a busca com diferen�as de caixa
 */
int busca_aluno(alunos alun[], char string[]){
    int i, achado=1;

    printf("Digite o nome do aluno a ser procurado: ");
    fflush(stdin);
    fgets(string, sizeof(string), stdin);

    strtok(string, "\n");

    for(i=0; i<=(sizeof(alun)/sizeof(alunos)); i++){
        if(strstr(alun[i].nome, string)){
            printf("Posi��o %d:\n", i+1);
            imp_aluno(alun[i]);
            achado--;
        }
        else
            achado++;
    }
    if(achado>0)
        printf("Aluno n�o encontrado\n");
}

int busca_aluno_dsc(alunos alun[], char string[], int cont){
    int i, j, achado=1;

    strtok(string, "\n");

    for(i=0; i<=strlen(string); i++)
        string[i]=toupper(string[i]);

    for(i=0; i<=cont; i++){
        for(j=0; j<3; j++){
            if(strstr(alun[i].disciplina[j].nome, string)){
                printf("Posi��o %d:\n", i+1);
                imp_aluno(alun[i]);
                achado--;
            }
        else
            achado++;
        }
    }
    if(achado>0)
        printf("Nenhum aluno encontrado para a disciplina procurada\n");
}

/*
 * A l�gia desta fun��o � levemente diferente, comparando o retorno da fun��o status_disciplina com a sigla
 * para aprovado ("AM").
 */
int busca_aluno_apr(alunos alun[], int cont){
    int i, j,  achado=1;

    for(i=0; i<=cont; i++){
        for(j=0; j<3; j++){
            if(status_disciplina(alun[i].disciplina[j])=="AM"){
                printf("Posi��o %d:\n", i+1);
                imp_dsc(alun[i], alun[i].disciplina[j]);
                achado--;
            }
        else
            achado++;
        }
    }
    if(achado>0)
        printf("Nenhum aluno aprovado encontrado\n");
}
/*
 * Para fins de praticidade a quantidade de alunos cadastrados fica dispon�vel no fim do menu.
 * Por ser uma opera��o repetitiva resolvi automatizar com uma fun��o.
 */
int menu(int n){

    imp_linha('-');
    imp_centralizado(" Bem vindo a UAB ", '-');
    imp_posicao(n);
    printf("Digite a op��o desejada: \n");
    printf("1 - Cadastrar aluno\n2 - Excluir aluno\n3 - Alterar aluno\n");
    printf("4 - Buscar aluno\n5 - Listar todos os alunos\n6 - Listar alunos por disciplina\n");
    printf("7 - Listar alunos aprovados\n8 - Sair\nOp��o: ");

    return 0;
}

/*
 * Resolvi usar uma abordagem levemente mais complexa, entretanto mais segura e flex�vel
 * Usei o sistema de parametros de chamada para receber o arquivo com o registro dos alunos
 * como param�tro. Os dados s�o lidos na interface de arquivo (fp) e tratados dentro da
 * pr�pria fun��o main.
 */
int main(int argC, char * argV[]){
    setlocale(LC_ALL, "portuguese"); //Permite a apresenta��o de acentua��o e cedilha
    FILE *fp; // Interface do arquivo
    alunos aluno[20]; // Array de alunos
    int entrada, pos, i=-1, j=0,  fim = -1;
    char nome[40], linha[50], string[40];
    char *arquivo; //Armazena o nome do arquivo

        if(argC==2){//Caso um arquivo seja passado como parametro, iniciamos o processo de carregamento
            arquivo=argV[1];
            fp = fopen(arquivo, "r");// carrega o arquivo
            if(fp){ // Caso n�o haja problemas com o carregamento do arquivo
                printf("Lista de alunos encontrada, carregando...\n");
                while(!feof(fp)){ //O loop b�sico da leitura do arquivo � sequencial, portando ele � lido linha a linha at� o fim do arquivo (feof - found end of file)
                    i++; //O i vai contar quantos alunos s�o lidos no arquivo. A contagem tanto � necess�ria para localizar os alunos no array, quanto para, no fim,
                         // podermos configurar a vari�vel fim de forma correta
                    fgets(linha, sizeof(linha), fp); // O fgets normalmente � usado para ler strings no stdin, mas neste caso le uma linha do arquivo, armazena seus dados
                                                     // na string linha
                    sscanf(linha, "%d", &aluno[i].matricula); // A fun��o sscanf tem basciamente a mesma fun��o da scanf, mas ao inv�s de capturar os dados no stdin
                                                              // ela l� uma as posi��es das vari�veis em uma string
                    // estes processos (armazenamento da linha e seu processamento nas vari�veis de cada item do aluno) � repetido at� o final do arquivo (feof)
                    fgets(linha, sizeof(linha), fp);
                    sscanf(linha, "%[^;]", &aluno[i].nome);
                    fgets(linha, sizeof(linha), fp);
                    sscanf(linha, "%[^;]", &aluno[i].endereco);
                    fgets(linha, sizeof(linha), fp);
                    sscanf(linha, "%d", &aluno[i].nascimento.dia);
                    fgets(linha, sizeof(linha), fp);
                    sscanf(linha, "%d", &aluno[i].nascimento.mes);
                    fgets(linha, sizeof(linha), fp);
                    sscanf(linha, "%d", &aluno[i].nascimento.ano);
                    for(j=0; j<3; j++){
                        fgets(linha, sizeof(linha), fp);
                        sscanf(linha, "%[^;]", &aluno[i].disciplina[j].nome);
                        fgets(linha, sizeof(linha), fp);
                        sscanf(linha, "%[^;]", &aluno[i].disciplina[j].professor);
                        fgets(linha, sizeof(linha), fp);
                        sscanf(linha, "%f %f %f", &aluno[i].disciplina[j].nota[0], &aluno[i].disciplina[j].nota[1], &aluno[i].disciplina[j].nota[2]);
                    }
                }
                if(i+1==1)
                    printf("1 aluno carregado\n");
                else
                    printf("%d alunos carregados\n", i+1);
                printf("Pressione ENTER para continuar...");
                getchar();
                system(LIMPAR);
            }
            fclose(fp);//Ap�s a leitura do arquivo ele � fechado
        }

    fim = i;
    i=0;


    /*
     * Abaixo temos o loop principal, com o tratamento das escolhas do usu�rio
     * O loop consiste de uma s�rie de desvios condicionais, que executam procedimentos internos
     * ou chamam fun��es.
     */
    while (entrada!=8) {
            menu(fim+1);
            scanf("%d", &entrada);

            if (entrada == 1 && fim < 20){
                if(fim<20){
                    printf("Posi��o %d\n", fim+2);
                    aluno[fim+1]= inclui_aluno(1);
                    fim++;
                }
            } else
            if (entrada == 2){

                printf("Informe a posi��o do aluno a ser eliminado: \n");
                scanf("%d", &pos);
                if(pos-1 <= fim){
                    char c;
                    imp_aluno(aluno[pos-1]);
                    printf("Certeza que deseja eliminar o aluno acima?(s/n) \n");
                    fflush(stdin);
                    scanf("%c", &c);

            if (toupper(c) == 'S'){
                for(i=pos-1; i<fim; i++){
                    aluno[i] = aluno[i+1];
                }
                fim--;
            }

            } else {
            printf("Imposs�vel excluir. Posi��o Inv�lida.\n");
            }

            } else
            if (entrada == 3){
                    printf("Informe a posi��o do aluno a ser alterada: ");
                    scanf("%d", &pos);
                    if ( fim >= 0 && pos-1 <= fim ){
                            imp_aluno(aluno[pos-1]);
                            printf("Voc� dever� incluir novamente os dados do aluno\n");
                            aluno[pos-1]=inclui_aluno(2);
                    } else {
                        printf("Imposs�vel alterar, posi��o n�o preenchida.\n");
                    }

            } else
            if (entrada == 4){
                printf("Digite o nome do aluno a ser procurado: ");
                fflush(stdin);
                fgets(string, sizeof(string), stdin);

                busca_aluno(aluno, string);

            } else
            if (entrada == 5){
                if(fim>=0){
                    imp_alunos(aluno, fim+1);
                } else {
                    printf("N�o existem alunos cadastrados\n");
                }

            } else
            if(entrada == 6){

                printf("Digite a disciplina a ser procurada: ");
                fflush(stdin);
                fgets(string, sizeof(string), stdin);

                busca_aluno_dsc(aluno, string, fim);

            } else
            if (entrada == 7){
                busca_aluno_apr(aluno, fim);
            }
            if (entrada == 1 && fim >= 19){
                printf("Imposs�vel cadastrar, vetor cheio\n");
            }
    }

    /*
     * Quando o usu�rio optar por encerrar o programa, o programa verifica a exist�ncia de registros preenchidos e
     * caso existam, verifica se o programa carregou arquivos em algum ponto e, caso negativo, gera um arquivo novo.
     */
    if(fim>=0){//Verifica a exist�ncia de registros preenchidos
        if(!arquivo){//Verifica se a variavel existe (se � nula), caso seja nulo a vari�vel � carregada com o nome padr�o
            arquivo="alunos.ini";
            fp = fopen(arquivo,"w+"); // Abre o arquivo para sobreescrita (apaga o conte�do antigo do arquivo e preenche com novos dados)
        } else
            fp = fopen(arquivo,"w+");

        if(fp){
            printf("Salvando lista de alunos...\n");
            i=0;
            for(i=0; i<=fim; i++){ //Este � o loop para saida dos dados para o arquivo, onde todas as posi��es do array (de 0 a fim) s�o escritas no arquivo
                fprintf(fp, "%ds\n", aluno[i].matricula); //A fun��o fprintf tem fun��o similar a fun��o printf, mas exige que seja informado um arquivo como param�tro
                fprintf(fp, "%s;\n", aluno[i].nome);
                fprintf(fp, "%s;\n", aluno[i].endereco);
                fprintf(fp, "%d\n %d\n %d\n", aluno[i].nascimento.dia, aluno[i].nascimento.mes, aluno[i].nascimento.ano);
                for(j=0; j<3; j++){
                    fprintf(fp, "%s;\n", aluno[i].disciplina[j].nome);
                    fprintf(fp, "%s;\n", aluno[i].disciplina[j].professor);
                        if(j==2 && i==fim)
                        fprintf(fp, "%.2f %.2f %.2f", aluno[i].disciplina[j].nota[0], aluno[i].disciplina[j].nota[1], aluno[i].disciplina[j].nota[2]);
                    else
                        fprintf(fp, "%.2f %.2f %.2f\n", aluno[i].disciplina[j].nota[0], aluno[i].disciplina[j].nota[1], aluno[i].disciplina[j].nota[2]);
                }
            }
        }
        fclose(fp);//Finalmente, o arquivo � fechado
        printf("Encerrando.\n");
    }


    return 0;
}

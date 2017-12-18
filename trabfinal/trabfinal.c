/*
 * Trabalho final da disciplina Laboratórios de programação, UAB V.
 * Aluno: Rammyres José Oliveira Pereira
 *
 * O programa é um sistema interativo simples, cujo objetivo é criar um registro com dados básicos de alunos.
 *
 * O programa utiliza strings para tratamento avançado das buscas. Também utiliza arquivos para armazenamento dos dados dos alunos.
 *
 * A fim de evitar problemas com o arquivamento e apresentação de caracteres acentuados, também usa localização.
 *
 * Peço que o responsável pela correção use o arquivo alunos.ini (incluido no arquivos) como parametro ao chamar o executável (c:\trabfinal alunos.ini ou
 * $ trabfinal alunos.ini) ele contém a lista de alunos necessários para cumprimento do requisito 'c' da lista.
 *
 */
 #ifdef _WIN32
    #define LIMPAR "cls"
#else
    #define LIMPAR "clear"
#endif // _WIN32

#include <stdio.h>
#include <string.h>
#include <locale.h> // Permite o uso da função setlocale, que altera os caracteres de saída, evitando erros de acentuação.
#include <unistd.h>

//Definição da estrututra data
typedef struct data {
    int dia, mes, ano;
} data;

//Definição da estrutura disciplinas
typedef struct disciplinas {
    char nome[60], professor[60];
    float nota[3];
} disciplinas;

//Definição da estrutura aluno
typedef struct alunos {
    long long matricula;
    char nome[40], endereco[60];
    disciplinas disciplina[3];
    data nascimento;
} alunos;

/* O objetivo desta e das funções imp_centralizado e imp_posicao é basicamente estético, melhorando a forma como
 * as informações são mostradas na primeira um loop imprime 80x o simbolo escolhido (largura padrão de terminais
 * VT100 e 3270).
 * A segunda tem a mesma lógica, mas imprime uma string no meio da linha e completa os demais espaços com o
 * caractere escolhidos.
 * A última imprime a posição fim em relação a quantidade máxima de registros.
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

/*  Apesar de eu preferir uma abordagem externa, utilizei esta função para coletar de forma interativa os dados cadastrais dos alunos, conforme
 * especificados na documentação. A função coleta os dados e retorna como um strunct aluno, que pode ser incluso numa string ou listado diretamente.
 * O parametro da função somente faz a diferenciação se é inclusão ou alteração, para fins estéticos.
 */

alunos inclui_aluno(int a){
    alunos alun;
    int i, j, k;

    if(a==1){
        imp_linha('=');
        printf("Inclusão de novo aluno\n");
        imp_linha('-');
    }
    if(a==2){
        imp_linha('=');
        printf("Alteração de aluno\n");
        imp_linha('-');
    }

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &alun.matricula);

    printf("Digite o nome do aluno: ");
    fflush(stdin);
    fgets(alun.nome, sizeof(alun.nome), stdin);
    strtok(alun.nome, "\n"); // A função dos diversos strtok (tokenizar strings) é manter somente a porção anterior ao retorno de carro na string.
                             // Caso os retornos fosse mantidos tanto a apresentação dos dados quanto a gravação e leitura do arquivo de registro
                             // seria comprometida, já que uma linha nula seria lida como se tivesse dados e criaria um registro com dados aleató-
                             // rios de memória, o que comprometeria a usabilidade do sistema.

    for(k=0; k<=strlen(alun.nome); k++) // Optei por registrar as strings todas em maisúsculas a fim de facilitar o trabalho do strstr, que faz comparação
                                        // a partir dos valores ASCCI (portanto inteiros) das letras, dificultando a busca
        alun.nome[k]=toupper(alun.nome[k]);

    printf("Digite o endereço do aluno: ");
    fflush(stdin);
    fgets(alun.endereco, sizeof(alun.endereco), stdin);
    strtok(alun.endereco, "\n");
    for(k=0; k<=strlen(alun.endereco); k++)
        alun.endereco[k]=toupper(alun.endereco[k]);

    printf("Digite agora a data de nascimento: \n");
    printf("Digite o dia: ");
    scanf("%d", &alun.nascimento.dia);
    printf("Digite o mês (janeiro = 01, fevereiro = 02): ");
    scanf("%d", &alun.nascimento.mes);
    printf("Digite o ano: ");
    scanf("%d", &alun.nascimento.ano);

    imp_linha('-');

    printf("Digite as disciplinas que o aluno esteja matriculado\n");

    for(i=0; i<3; i++){
        imp_linha('-');
        printf("Digite o nome da %dª disciplina: ", i+1);
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
            printf("Digite a %dª nota: ", j+1);
            scanf("%f", &alun.disciplina[i].nota[j]);
        }
    }

    return alun;
}
/*
 * Considerando as limitações das especificaçoes das estruturas aluno e disciplina, não é possíve registrar nem a média
 * nem o status do aluno diretamente no array, a função, no entanto, facilita a leitura e pode, inclusive, automatizar
 * a busca de alunos aprovados, já que o retorno é facilmente usado para comparação
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
 * Considerando que a especifição do item "j" é levemente diferente da especificação dos demais itens,
 * detalhando que somente alguns itens devem ser impressos, ao invés da ficha cadastral inteira do aluno
 * optei por cirar uma função especifica, que recebe por parametro o aluno, para coleta dos dados pessoais
 * indicados na questão e a disicplina especifica, permitindo a apresentação dos dados informados na
 * especificação
 */

int imp_dsc(alunos alun, disciplinas dsc){

        imp_linha('=');
        printf("Matricula: %d\n", alun.matricula);
        printf("Nome: %s\n", alun.nome);
        printf("Disciplina: %s\n", dsc.nome);
        printf("Professor: %s\n", dsc.professor);
        printf("Notas: %.2f %.2f %.2f \nMédia: %.2f\n", dsc.nota[0], dsc.nota[1], dsc.nota[2], (dsc.nota[0]+dsc.nota[1]+dsc.nota[2])/3);
        printf("Status %s\n", status_disciplina(dsc));
        imp_linha('=');
        return 0;
}

/*
 * Conforme especificado no comentário acima, há uma diferença entre a impressão do aluno (usado na maioria das
 * buscas e a especifica de alunos aprovados. Aqui é temos a função usada para a impressão de todos os dados da ficha
 * cadastral completa do aluno. A função recebe somente um struct aluno como parametro e imprime seus dados no stdin
 */
int imp_aluno(alunos alun){
        int i, j;

        imp_linha('=');
        printf("Matricula: %d\n", alun.matricula);
        printf("Nome: %s\n", alun.nome);
        printf("Endereço: %s\n", alun.endereco);
        printf("Data de nascimento: %d/%d/%d\n", alun.nascimento.dia, alun.nascimento.mes, alun.nascimento.ano);
        imp_linha('-');
        printf("Disciplinas que o aluno está matriculado\n");
        for(i=0; i<3; i++){
            imp_linha('-');
            printf("Disciplina %d: %s\n", i+1, alun.disciplina[i].nome);
            printf("Professor: %s\n", alun.disciplina[i].professor);
            printf("Notas: %.2f %.2f %.2f \nMédia: %.2f\n", alun.disciplina[i].nota[0], alun.disciplina[i].nota[1], alun.disciplina[i].nota[2], (alun.disciplina[i].nota[0]+alun.disciplina[i].nota[1]+alun.disciplina[i].nota[2])/3);
            printf("Status %s\n", status_disciplina(alun.disciplina[i]));
        }
        imp_linha('=');

        return 0;
}

/*
 * Considerando a especificação do item "i", optei por automatizar a partir de uma função especifica
 * a listagem de alunos cadastrados, usando como base o array de alunos, diretamente. Como a contagem
 * a partir do array não é possível e a abordagem da contagem da memória (memoria alocada/memmoria necessaria
 * para o scruct, que em tese deveria ser um inteiro) é traiçoeira (já que depende de como o sistema operacional
 * trata alocadores e ponteiros) e o tratamento dessas diferenças tornariam o programa muito mais complexo
 * optei por receber diretamente pela variavel "fim" a quantidade de alunos existentes
*/

int imp_alunos(alunos aluns[], int num){
    int i;
    for (i=0; i<num; i++){
        printf("Posição: %d\n", i+1);
        imp_aluno(aluns[i]);
    }
    return 0;
}


/*
 * As dunções de busca abaixo tem basicamente a mesma lógica, comparam a string passada
 * com a variável correspondente  (strstr) num loop for e usam um flag para indicar quando nenhum
 * aluno for localizado. Os dados dos alunos são registrados em maisculas em decorrência da limitação
 * do C que usa char como inteiros (padrão ASCII), tornando mais dificil a busca com diferenças de caixa
 */
int busca_aluno(alunos alun[], char string[]){
    int i, achado=1;

    printf("Digite o nome do aluno a ser procurado: ");
    fflush(stdin);
    fgets(string, sizeof(string), stdin);

    strtok(string, "\n");

    for(i=0; i<=(sizeof(alun)/sizeof(alunos)); i++){
        if(strstr(alun[i].nome, string)){
            printf("Posição %d:\n", i+1);
            imp_aluno(alun[i]);
            achado--;
        }
        else
            achado++;
    }
    if(achado>0)
        printf("Aluno não encontrado\n");
}

int busca_aluno_dsc(alunos alun[], char string[], int cont){
    int i, j, achado=1;

    strtok(string, "\n");

    for(i=0; i<=strlen(string); i++)
        string[i]=toupper(string[i]);

    for(i=0; i<=cont; i++){
        for(j=0; j<3; j++){
            if(strstr(alun[i].disciplina[j].nome, string)){
                printf("Posição %d:\n", i+1);
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
 * A lógia desta função é levemente diferente, comparando o retorno da função status_disciplina com a sigla
 * para aprovado ("AM").
 */
int busca_aluno_apr(alunos alun[], int cont){
    int i, j,  achado=1;

    for(i=0; i<=cont; i++){
        for(j=0; j<3; j++){
            if(status_disciplina(alun[i].disciplina[j])=="AM"){
                printf("Posição %d:\n", i+1);
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
 * Para fins de praticidade a quantidade de alunos cadastrados fica disponível no fim do menu.
 * Por ser uma operação repetitiva resolvi automatizar com uma função.
 */
int menu(int n){

    imp_linha('-');
    imp_centralizado(" Bem vindo a UAB ", '-');
    imp_posicao(n);
    printf("Digite a opção desejada: \n");
    printf("1 - Cadastrar aluno\n2 - Excluir aluno\n3 - Alterar aluno\n");
    printf("4 - Buscar aluno\n5 - Listar todos os alunos\n6 - Listar alunos por disciplina\n");
    printf("7 - Listar alunos aprovados\n8 - Sair\nOpção: ");

    return 0;
}

/*
 * Resolvi usar uma abordagem levemente mais complexa, entretanto mais segura e flexível
 * Usei o sistema de parametros de chamada para receber o arquivo com o registro dos alunos
 * como paramêtro. Os dados são lidos na interface de arquivo (fp) e tratados dentro da
 * própria função main.
 */
int main(int argC, char * argV[]){
    setlocale(LC_ALL, "portuguese"); //Permite a apresentação de acentuação e cedilha
    FILE *fp; // Interface do arquivo
    alunos aluno[20]; // Array de alunos
    int entrada, pos, i=-1, j=0,  fim = -1;
    char nome[40], linha[50], string[40];
    char *arquivo; //Armazena o nome do arquivo

        if(argC==2){//Caso um arquivo seja passado como parametro, iniciamos o processo de carregamento
            arquivo=argV[1];
            fp = fopen(arquivo, "r");// carrega o arquivo
            if(fp){ // Caso não haja problemas com o carregamento do arquivo
                printf("Lista de alunos encontrada, carregando...\n");
                while(!feof(fp)){ //O loop básico da leitura do arquivo é sequencial, portando ele é lido linha a linha até o fim do arquivo (feof - found end of file)
                    i++; //O i vai contar quantos alunos são lidos no arquivo. A contagem tanto é necessária para localizar os alunos no array, quanto para, no fim,
                         // podermos configurar a variável fim de forma correta
                    fgets(linha, sizeof(linha), fp); // O fgets normalmente é usado para ler strings no stdin, mas neste caso le uma linha do arquivo, armazena seus dados
                                                     // na string linha
                    sscanf(linha, "%d", &aluno[i].matricula); // A função sscanf tem basciamente a mesma função da scanf, mas ao invés de capturar os dados no stdin
                                                              // ela lê uma as posições das variáveis em uma string
                    // estes processos (armazenamento da linha e seu processamento nas variáveis de cada item do aluno) é repetido até o final do arquivo (feof)
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
            fclose(fp);//Após a leitura do arquivo ele é fechado
        }

    fim = i;
    i=0;


    /*
     * Abaixo temos o loop principal, com o tratamento das escolhas do usuário
     * O loop consiste de uma série de desvios condicionais, que executam procedimentos internos
     * ou chamam funções.
     */
    while (entrada!=8) {
            menu(fim+1);
            scanf("%d", &entrada);

            if (entrada == 1 && fim < 20){
                if(fim<20){
                    printf("Posição %d\n", fim+2);
                    aluno[fim+1]= inclui_aluno(1);
                    fim++;
                }
            } else
            if (entrada == 2){

                printf("Informe a posição do aluno a ser eliminado: \n");
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
            printf("Impossível excluir. Posição Inválida.\n");
            }

            } else
            if (entrada == 3){
                    printf("Informe a posição do aluno a ser alterada: ");
                    scanf("%d", &pos);
                    if ( fim >= 0 && pos-1 <= fim ){
                            imp_aluno(aluno[pos-1]);
                            printf("Você deverá incluir novamente os dados do aluno\n");
                            aluno[pos-1]=inclui_aluno(2);
                    } else {
                        printf("Impossível alterar, posição não preenchida.\n");
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
                    printf("Não existem alunos cadastrados\n");
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
                printf("Impossível cadastrar, vetor cheio\n");
            }
    }

    /*
     * Quando o usuário optar por encerrar o programa, o programa verifica a existência de registros preenchidos e
     * caso existam, verifica se o programa carregou arquivos em algum ponto e, caso negativo, gera um arquivo novo.
     */
    if(fim>=0){//Verifica a existência de registros preenchidos
        if(!arquivo){//Verifica se a variavel existe (se é nula), caso seja nulo a variável é carregada com o nome padrão
            arquivo="alunos.ini";
            fp = fopen(arquivo,"w+"); // Abre o arquivo para sobreescrita (apaga o conteúdo antigo do arquivo e preenche com novos dados)
        } else
            fp = fopen(arquivo,"w+");

        if(fp){
            printf("Salvando lista de alunos...\n");
            i=0;
            for(i=0; i<=fim; i++){ //Este é o loop para saida dos dados para o arquivo, onde todas as posições do array (de 0 a fim) são escritas no arquivo
                fprintf(fp, "%ds\n", aluno[i].matricula); //A função fprintf tem função similar a função printf, mas exige que seja informado um arquivo como paramêtro
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
        fclose(fp);//Finalmente, o arquivo é fechado
        printf("Encerrando.\n");
    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

/****************************************
 * Nome: Willian Custodio Quintino      *
 * RA: 0040962323006                    *
 *                                      *
 * Nome:                                *
 * RA:                                  *
 *                                      *
 * Nome:                                *
 * RA:                                  *
 ****************************************

 * Deve conter
 * La�o
 * If .. else
 * Modulariza��o - OBRIGATORIO
 * Ponteiro
 * Vetores
 * Manipula��o de string - OBRIGATORIO
 * Manipula��o de Arquivos Texto - OBRIGATORIO
 * Registro - OBRIGATORIO
 * Manipula��o de Arquivos Binarios - OBRIGATORIO
 * Lista Duplamente encadeada - OBRIGATORIO
*/

// Estrutura para armazenar informa��es de uma pessoa
typedef struct tipopessoa {
    int id[10];
    char nome[50];
    char sexo[2];
    char email[199];
    char senha[50];
    int dia[3];
    int mes[3];
    int ano[5];
    char cidade[10];
    char estado[3];
    char pais[10];
    int pontos;
    struct tipopessoa *next, *back;
} tipopessoa;

// Estrutura para armazenar informa��es de uma Leaderboard
typedef struct {
    char nome[50];
    int pontos;
    char data[20]; // A data ser� armazenada como uma string no formato "dd/mm/aaaa"
} LeaderboardEntry;


// Vari�veis globais para a lista de pessoas
struct tipopessoa *auxiliar, *auxiliar2, *corrente, *inicio, *fim;


// 1 = Cross | 2 = Circle | 0 = White
int game = 0,
    player = 0,
    machine = 0,
    end = 0,
    pontos = 0,
    matrix[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
    };
char *leaderboardFile = "leaderboard.dat",
     *pessoasFile = "pessoas.dat";


void inserirNaLeaderboard(const char *nome, int pontos);
void listarDadosUsuarioAtual(char *email, char *senha);
void listarDadosUsuario(char *email, char *senha);
void editarDados(char *email, char *senha);
void ordenarPorNome(tipopessoa *inicio);
void PrintGame(int colunaLinha);
void recuperarLeaderboard();
void Line(int colunaLinha);
void HeadCol(int j, int i);
void Circle(int j, int l);
void removerArquivosDat();
void Cross(int j, int l);
void listarTodosDados();
void MaquinaOptions();
void salvarPessoa();
void PrintOptions();
void InitialForm();
void Continuar();
void Enterdata();
void HeadLine();
void EndGame();
void White();
int compararPontuacao(const void *a, const void *b);
int verificarEmail(char email[199]);
int verificarSenha(char senha[50]);
int MaquinaJoga();
int Ganhou();

int main()
{
    setlocale(LC_CTYPE, "portuguese");// Configura��o acento

    //inserirNaLeaderboard("Jo�o", 12);
    char email[199], senha[50];
    int op, vezes, auth=0;

    corrente = NULL;
    inicio = NULL;
    auxiliar = NULL;

    printf("Informe o email: ");
    scanf("%s", email);
    while (getchar() != '\n'); // Limpar o buffer de entrada
    if (verificarEmail(email)) {
        while(vezes < 6)
        {
            printf("Informe a senha: ");
            scanf("%s", senha);
            while (getchar() != '\n'); // Limpar o buffer de entrada
            if(verificarSenha(senha))
            {
                printf("\nUsu�rio e senha V�lidados.\n");
                system("pause");
                auth = 1;
                break;
            }else{
                printf("\nUsu�rio e senha inv�lidos.\n");
                system("pause");
                vezes++;
            }
        }
    } else {
        InitialForm();
        salvarPessoa();
        while(vezes < 6)
        {
            senha[50] = NULL;
            printf("Informe a senha: ");
            scanf("%s", senha);
            char senhaSave = senha;
            while (getchar() != '\n'); // Limpar o buffer de entrada
            if(verificarSenha(senha))
            {
                printf("\nUsu�rio e senha V�lidados.\n");
                system("pause");
                auth = 1;
                break;
            }else{
                printf("\nUsu�rio e senha inv�lidos.\n");
                system("pause");
                vezes++;
            }
        }
    }

    if(auth == 0)
    {
        exit(0);
    }

    do
    {
        listarDadosUsuarioAtual(email,senha);
        printf("\n******** Lista Simplesmente Encadeada *******");
        printf("\n [1] Iniciar Jogo da Velha");
        printf("\n [2] Ver Leader Board");
        printf("\n [3] Visualizar o seu Cadastro");
        printf("\n [4] Editar Cadastro");
        printf("\n [5] Listar todos os dados");
        printf("\n [6] Sair");

        printf("\n Escolha a Op��o: ");

        while (scanf("%d", &op) != 1)
        {
            printf("\nValor inv�lido. Insira um n�mero inteiro: ");
            // Limpar o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        switch (op)
        {
        case 1:
            PrintOptions();;
            break;
        case 2:
            recuperarLeaderboard();
            break;
        case 3:
            listarDadosUsuario(email, senha);
            break;
        case 4:
            editarDados(email, senha);
            break;
        case 5:
            listarTodosDados();
            break;
        case 6:
            exit(0);
            break;
        case 99:
            removerArquivosDat();
            break;
        default:
            printf("\n Fun��o n�o encontrada.. tente novamente");
            system("pause");
        }
    }while(op != 6);

    system("cls");
    printf("\n Final de processamento \n");
    system("pause");

    return 0;

}


void HeadLine()
{
    printf("  ");
    for (int m = 0; m < 3; m++)
    {
        for (int l = 0; l < 14; l++)
        {
            if(l == 7)
            {
                printf("%i", m);
            }
            else
            {
                printf(" ");
            }

        }
    }
    printf("\n");
}

void HeadCol(int j, int i)
{
    if(j == 5)
    {
        printf(" %i ", i);
    }
    else
    {
        printf("   ");
    }
}

void Line(int colunaLinha)
{
    if(colunaLinha == 1){printf("   ");}
    for (int l = 0; l < 14*3; l++)
    {
      printf("#");
    }

}

void Cross(int j, int l)
{
    char figura[9][14] = {
        "..............",
        "...XX....XX...",
        "....XX..XX....",
        ".....XXXX.....",
        "......XX......",
        ".....XXXX.....",
        "....XX..XX....",
        "...XX....XX...",
        ".............."
    };
    printf("%c", figura[j][l]);
}

void Circle(int j, int l)
{
    char figura[9][14] = {
        "..............",
        "....OOOOOO....",
        "...OO....OO...",
        "...O......O...",
        "...O......O...",
        "...O......O...",
        "...OO....OO...",
        "....OOOOOO....",
        ".............."
    };
    printf("%c", figura[j][l]);
}

void White()
{
    printf(".");
}

void PrintGame(int colunaLinha)
{
    if(colunaLinha == 2){HeadLine();}
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(colunaLinha == 1){HeadCol(j,i);}
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 14; l++)
                {
                    if ((k == 0 && l == 13) || (k == 1 && (l == 0 || l == 13)) || (k == 2 && l == 0))
                    {
                        printf("#");
                    }
                    else
                    {
                        switch(matrix[i][k])
                        {
                            case 1:
                                Cross(j, l);
                                break;
                            case 2:
                                Circle(j, l);
                                break;
                            default:
                                White();
                                break;
                        }
                    }
                }
            }
            if(colunaLinha == 1){HeadCol(j,i);}
            printf("\n");
        }
        if(i != 2)
        {
          Line(colunaLinha);
        }
        printf("\n");
    }
    if(colunaLinha == 2){HeadLine();}
}

void PrintOptions()
{
    if(Ganhou() == 1)
    {
        player++;
        end = 1;
        PrintGame(0);
        corrente->pontos += pontos;
        printf("\nPrint o %s ganho desta vez!!!!\n", corrente->nome);
        EndGame();
    }
    else if (Ganhou() == 2)
    {
        machine++;
        end = 1;
        PrintGame(0);
        printf("\nPrint o M�quina ganhou desta vez!!!!\n");
        EndGame();
        MaquinaOptions();
    }

    int linha, coluna;
    PrintGame(1);

    printf("\nDigite o n�mero da Linha: ");
    while (scanf("%d", &linha) != 1)
    {
        printf("\nValor inv�lido. Insira um n�mero inteiro: ");
        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    PrintGame(2);
    printf("\nDigite o n�mero da Coluna: ");
    while (scanf("%d", &coluna) != 1)
    {
        printf("\nValor inv�lido. Insira um n�mero inteiro: ");
        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    if(matrix[linha][coluna] == 0)
    {
        matrix[linha][coluna] = 1;
    }
    else
    {
        PrintOptions();
    }

    if(Ganhou() == 1)
    {
        player++;
        end = 1;
        PrintGame(0);
        printf("\nPrint o %s ganho desta vez!!!!\n", corrente->nome);
        EndGame();
    }
    else if (Ganhou() == 2)
    {
        machine++;
        end = 1;
        PrintGame(0);
        printf("\nPrint o M�quina ganhou desta vez!!!!\n");
        EndGame();
        MaquinaOptions();
    }
    EndGame();
    MaquinaOptions();

    system("cls");

    PrintGame(1);
}

int MaquinaJoga()
{
    // Implemente a l�gica para a m�quina decidir onde jogar
    // Retorna a posi��o na matriz onde a m�quina quer jogar

    // Verificar se a m�quina pode ganhar na pr�xima jogada
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = 2;
                if (Ganhou() == 2) {
                    matrix[i][j] = 0;
                    return i * 3 + j; // Retorna a posi��o da matriz
                }
                matrix[i][j] = 0;
            }
        }
    }

    // Verificar se o jogador pode ganhar na pr�xima jogada e bloquear
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = 1;
                if (Ganhou() == 1) {
                    matrix[i][j] = 2;
                    return i * 3 + j; // Retorna a posi��o da matriz
                }
                matrix[i][j] = 0;
            }
        }
    }

    // Tentar jogar no centro se estiver vazio
    if (matrix[1][1] == 0) {
        return 4; // Retorna a posi��o da matriz
    }

    // Tentar jogar em um canto se estiver vazio
    int cantos[] = {0, 2, 6, 8};
    for (int i = 0; i < 4; i++) {
        int linha = cantos[i] / 3;
        int coluna = cantos[i] % 3;
        if (matrix[linha][coluna] == 0) {
            return cantos[i]; // Retorna a posi��o da matriz
        }
    }

    // Jogar em uma posi��o aleat�ria vazia
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                return i * 3 + j; // Retorna a posi��o da matriz
            }
        }
    }

    return -1; // Retorna -1 se n�o houver posi��o dispon�vel (isso n�o deve acontecer)
}

void MaquinaOptions()
{
    int posicao = MaquinaJoga(); // Armazena a posi��o retornada por MaquinaJoga

    // Calcular o endere�o do elemento na matriz usando ponteiro
    int linha = posicao / 3; // Calcula a linha da matriz
    int coluna = posicao % 3; // Calcula a coluna da matriz

    // Verificar se a posi��o est� vazia
    printf("\nLinha: %i\n", linha);
    printf("\nColuna: %i", coluna);
    printf("\nposicao: %i\n", posicao);
    printf("\nTabela valor: %i", matrix[linha][coluna]);
    printf("\nse igual a 0: %i\n", matrix[linha][coluna] == 0);
    if (matrix[linha][coluna] == 0) {
        matrix[linha][coluna] = 2; // Marca a posi��o como ocupada pela m�quina
    }

    // Ap�s marcar a posi��o, imprimir as op��es dispon�veis
    PrintOptions();
}

void EndGame()
{
    int soma = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma += matrix[i][j];
        }
    }

    if(end)
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = 0;
            }
        }
        game++;
        end=0;
        pontos = 14 - soma + game;
        Continuar();
    }

    if(game % 2 == 0){
        if(soma > 12)
        {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    matrix[i][j] = 0;
                }
            }
            game++;
            Continuar();
        }
    }
    else
    {
        if(soma > 11)
        {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    matrix[i][j] = 0;
                }
            }
            game++;
            Continuar();
            PrintOptions();
        }
    }
}

int Ganhou()
{
    if((matrix[0][0]==matrix[0][1] && matrix[0][0]==matrix[0][2])||
       (matrix[0][0]==matrix[1][0] && matrix[0][0]==matrix[2][0])||
       (matrix[0][0]==matrix[1][1] && matrix[0][0]==matrix[2][2]))
    {
        return matrix[0][0];
    }
    else if((matrix[0][1]==matrix[1][1] && matrix[0][1]==matrix[2][1]))
    {
       return matrix[0][1];
    }
    else if((matrix[0][2]==matrix[1][1] && matrix[0][2]==matrix[2][0])||
            (matrix[0][2]==matrix[1][2] && matrix[0][2]==matrix[2][2]))
    {
        return matrix[0][2];
    }
    else if((matrix[1][0]==matrix[1][1] && matrix[1][0]==matrix[1][2]))
    {
        return matrix[1][0];
    }
    else if((matrix[2][0]==matrix[2][1] && matrix[2][0]==matrix[2][2]))
    {
        return matrix[2][0];
    }
    return 0;
}

void Continuar()
{
    int stop;

    while (1) {
        printf("\nPlacar do jogo %i\nJogador: %i\nM�quina: %i\nPontos do Jogador: %i\n", game, player, machine, corrente->pontos);
        printf("\nDeseja continuar?\n1: para sim\n2: para n�o\nDigite a op��o: ");

        if (scanf("%d", &stop) != 1) {
            printf("Entrada inv�lida. Digite um n�mero inteiro.\n");
            // Limpar o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        if (stop == 1 || stop == 2) {
            break;
        } else {
            printf("Op��o inv�lida. Digite 1 ou 2.\n");
        }
    }

    if (stop == 2) {
        inserirNaLeaderboard(corrente->nome, corrente->pontos);
        main();
    }
}

void removerArquivosDat() {
    if (remove(leaderboardFile) == 0) {
        printf("Arquivo leaderboard.dat removido com sucesso.\n");
    } else {
        printf("Erro ao remover o arquivo leaderboard.dat.\n");
    }

    if (remove(pessoasFile) == 0) {
        printf("Arquivo pessoas.dat removido com sucesso.\n");
    } else {
        printf("Erro ao remover o arquivo pessoas.dat.\n");
    }
    system("pause");
    exit(0);
}

// Fun��o de compara��o para qsort
int compararPontuacao(const void *a, const void *b) {
    const LeaderboardEntry *pa = (const LeaderboardEntry *)a;
    const LeaderboardEntry *pb = (const LeaderboardEntry *)b;
    return pb->pontos - pa->pontos; // Ordenar em ordem decrescente
}

// Fun��o para inserir dados de uma pessoa na leaderboard e salvar em um arquivo .dat
void inserirNaLeaderboard(const char *nome, int pontos) {
    // Criar uma inst�ncia da estrutura LeaderboardEntry
    LeaderboardEntry pessoa;

    // Copiar o nome e a pontua��o fornecidos para a estrutura
    strncpy(pessoa.nome, nome, sizeof(pessoa.nome) - 1);
    pessoa.nome[sizeof(pessoa.nome) - 1] = '\0'; // Garantir que a string do nome est� terminada
    pessoa.pontos = pontos;

    // Obter a data atual
    time_t t = time(NULL);
    struct tm *data_atual = localtime(&t);
    strftime(pessoa.data, sizeof(pessoa.data), "%d/%m/%Y", data_atual);

    // Abrir o arquivo para leitura e escrita no modo bin�rio
    FILE *arquivo = fopen(leaderboardFile, "ab+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escrever a estrutura no arquivo
    fwrite(&pessoa, sizeof(LeaderboardEntry), 1, arquivo);

    // Fechar o arquivo
    fclose(arquivo);

    printf("Dados salvos com sucesso!\n");
}

// Fun��o para recuperar os dados da leaderboard
void recuperarLeaderboard() {
    // Abrir o arquivo para leitura no modo bin�rio
    FILE *arquivo = fopen(leaderboardFile, "rb");
    if (arquivo == NULL) {
        printf("N�o tem ainda uma Leaderboard.\n");
        return;
    }

    // Vari�vel para armazenar todos os registros
    LeaderboardEntry pessoas[100]; // Supondo um m�ximo de 100 registros

    // Vari�vel para contar o n�mero de registros lidos
    int num_registros = 0;

    // Ler cada registro do arquivo e armazenar na array de pessoas
    LeaderboardEntry pessoa;
    while (fread(&pessoa, sizeof(LeaderboardEntry), 1, arquivo) == 1) {
        pessoas[num_registros++] = pessoa;
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Ordenar as pessoas pelo n�mero de pontos usando qsort
    qsort(pessoas, num_registros, sizeof(LeaderboardEntry), compararPontuacao);

    printf("=== Leaderboard Ordenada por Pontua��o ===\n");
    // Imprimir os dados de cada pessoa
    for (int i = 0; i < num_registros; i++) {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Pontos: %d\n", pessoas[i].pontos);
        printf("Data: %s\n", pessoas[i].data);
        printf("-----------------------------\n");
    }
}

void Enterdata()
{
    printf("\n Informe o seu email: ");
    scanf("%198s", &corrente->email);
    while (getchar() != '\n'); // Limpar o buffer de entrada

    printf("\n Informe a sua senha: ");
    scanf("%49s", &corrente->senha);
    while (getchar() != '\n'); // Limpar o buffer de entrada

    printf("\n Informe o seu nome: ");
    scanf("%49s", &corrente->nome);
    while (getchar() != '\n'); // Limpar o buffer de entrada

    printf("\n Informe o sexo [M, F]: ");
    scanf("%s", &corrente->sexo);
    while (getchar() != '\n'); // Limpar o buffer de entrada

    printf("\n Informe a Dia de nascimento: [31]: ");
    while (scanf("%d", &corrente->dia) != 1)
    {
        printf("\nValor inv�lido. Insira um n�mero inteiro: ");
        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("\n Informe o M�s de nascimento: [12]: ");
    while (scanf("%d", &corrente->mes) != 1)
    {
        printf("\nValor inv�lido. Insira um n�mero inteiro: ");
        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("\n Informe a Ano de nascimento: [1999]: ");
    while (scanf("%d", &corrente->ano) != 1)
    {
        printf("\nValor inv�lido. Insira um n�mero inteiro: ");
        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("\n Informe o nome da Cidades: ");
    scanf("%9s", &corrente->cidade);
    while (getchar() != '\n'); // Limpar o buffer de entrada

    printf("\n Informe o estado [SP]: ");
    scanf(" %2s", &corrente->estado);
    while (getchar() != '\n'); // Limpar o buffer de entrada

    printf("\n Informe o nome do pa�s: ");
    scanf("%9s", &corrente->pais);
    while (getchar() != '\n'); // Limpar o buffer de entrada
}

void salvarPessoa() {
    // Abrir o arquivo para escrita no modo bin�rio
    int x;
    x=0;
    tipopessoa pessoa;
    corrente = inicio;

    FILE *arquivo = fopen(pessoasFile, "ab+");

    while(fread(&pessoa,sizeof(tipopessoa), 1, arquivo))
    {
        x++;
    }

    *corrente->id=x;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Ordenar os registros pelo nome antes de salvar
    ordenarPorNome(inicio);

    // Escrever os registros no arquivo
    while (corrente != NULL) {
        pessoa = *corrente; // Copiar o conte�do do n� atual para a vari�vel pessoa
        fwrite(&pessoa, sizeof(tipopessoa), 1, arquivo);
        corrente = corrente->next;
    }

    // Fechar o arquivo
    fclose(arquivo);
}

int verificarEmail(char email[199]) {
    FILE *arquivo = fopen(pessoasFile, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0; // Retornar 0 em caso de erro
    }

    tipopessoa pessoa;
    while (fread(&pessoa, sizeof(tipopessoa), 1, arquivo) == 1) {
        if (strcmp(pessoa.email, email) == 0) {
            fclose(arquivo);
            return 1; // Retornar 1 se o email for encontrado
        }
    }

    fclose(arquivo);
    return 0; // Retornar 0 se o email n�o for encontrado
}

int verificarSenha(char senha[50]) {
    FILE *arquivo = fopen(pessoasFile, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0; // Retornar 0 em caso de erro
    }

    tipopessoa pessoa;
    while (fread(&pessoa, sizeof(tipopessoa), 1, arquivo) == 1) {
        if (strcmp(pessoa.senha, senha) == 0) {
            fclose(arquivo);
            return 1; // Retornar 1 se a senha for encontrada
        }
    }

    fclose(arquivo);
    return 0; // Retornar 0 se a senha n�o for encontrada
}

void editarDados(char *email, char *senha) {
    // Vari�vel para armazenar um registro lido do arquivo
    tipopessoa pessoa;
    int c = 0;

    // Abrir o arquivo para leitura e escrita no modo bin�rio
    FILE *arquivo = fopen(pessoasFile, "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    else {
        while (fread(&pessoa, sizeof(tipopessoa), 1, arquivo) == 1) {
            if (strcmp(pessoa.email, email) == 0 && strcmp(pessoa.senha, senha) == 0) {
                // Usu�rio encontrado, permitir a edi��o dos dados
                printf("Digite os novos dados:\n");

                printf("\n Nome ........:%s", pessoa.nome);
                printf("\n Redigite o Nome ..... :");
                scanf("%49s", pessoa.nome); // Use %49s to prevent buffer overflow
                while (getchar() != '\n'); // Limpar o buffer de entrada

                printf("\n Sexo ........:%s", pessoa.sexo);
                printf("\n Redigite o Sexo ..... :");
                scanf("%1s", pessoa.sexo); // Use %1s to prevent buffer overflow
                while (getchar() != '\n'); // Limpar o buffer de entrada

                printf("\n Email........:%s", pessoa.email);
                printf("\n Redigite o Email .... :");
                scanf("%98s", pessoa.email); // Use %98s to prevent buffer overflow
                while (getchar() != '\n'); // Limpar o buffer de entrada

                printf("\n Senha........:%s", pessoa.senha);
                printf("\n Redigite o Senha .... :");
                scanf("%49s", pessoa.senha); // Use %49s to prevent buffer overflow
                while (getchar() != '\n'); // Limpar o buffer de entrada

                printf("\n Dia .........:%d", pessoa.dia[0]);
                printf("\n Redigite o Dia ...... :");
                while (scanf("%d", &pessoa.dia[0]) != 1) {
                    printf("\nValor inv�lido. Insira um n�mero inteiro: ");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                }

                printf("\n M�s .........:%d", pessoa.mes[0]);
                printf("\n Redigite a M�s ...... :");
                while (scanf("%d", &pessoa.mes[0]) != 1) {
                    printf("\nValor inv�lido. Insira um n�mero inteiro: ");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                }

                printf("\n Ano .........:%d", pessoa.ano[0]);
                printf("\n Redigite a Ano ...... :");
                while (scanf("%d", &pessoa.ano[0]) != 1) {
                    printf("\nValor inv�lido. Insira um n�mero inteiro: ");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                }

                printf("\n Cidade.......:%s", pessoa.cidade);
                printf("\n Redigite o Cidade ... :");
                scanf("%9s", pessoa.cidade); // Use %9s to prevent buffer overflow
                while (getchar() != '\n'); // Limpar o buffer de entrada

                printf("\n Estado.......:%s", pessoa.estado);
                printf("\n Redigite o Estado ... :");
                scanf("%2s", pessoa.estado); // Use %2s to prevent buffer overflow
                while (getchar() != '\n'); // Limpar o buffer de entrada

                printf("\n Pais.........:%s", pessoa.pais);
                printf("\n Redigite o Pais ..... :");
                scanf("%9s", pessoa.pais); // Use %9s to prevent buffer overflow
                while (getchar() != '\n'); // Limpar o buffer de entrada

                // Posicionar o ponteiro de arquivo no local correto antes de escrever
                fseek(arquivo, -sizeof(tipopessoa), SEEK_CUR);

                // Escrever os novos dados no arquivo
                fwrite(&pessoa, sizeof(tipopessoa), 1, arquivo);
                printf("Dados do usu�rio editados com sucesso.\n");
                system("pause");
                break;
            }
            c++;
        }
        if (c == 0) {
            printf("\n Registro n�o consta na Base de Dados");
            printf("\n\n");
            system("pause");
        }
    }
    fclose(arquivo);
    main();
}

void listarDadosUsuario(char *email, char *senha) {
    // Abrir o arquivo para leitura no modo bin�rio
    FILE *arquivo = fopen(pessoasFile, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Vari�vel para armazenar um registro lido do arquivo
    tipopessoa pessoa;

    // Ler e buscar o usu�rio atual no arquivo
    while (fread(&pessoa, sizeof(tipopessoa), 1, arquivo) == 1) {
        if (strcmp(pessoa.email, email) == 0 && strcmp(pessoa.senha, senha) == 0) {
            // Usu�rio encontrado, imprimir os dados
            printf("ID: %s\n", pessoa.id);
            printf("Nome: %s\n", pessoa.nome);
            printf("Email: %s\n", pessoa.email);
            printf("Senha: %s\n", pessoa.senha);
            printf("Sexo: %c\n", pessoa.sexo);
            printf("Data de nascimento: %s/%s/%s\n", pessoa.dia, pessoa.mes, pessoa.ano);
            printf("Cidade: %s\n", pessoa.cidade);
            printf("Estado: %s\n", pessoa.estado);
            printf("Pa�s: %s\n", pessoa.pais);
            printf("-----------------------------\n");
            fclose(arquivo);
            return;
        }
    }
    printf("Usu�rio n�o encontrado.\n");
    fclose(arquivo);
}

void listarTodosDados() {
    // Abrir o arquivo para leitura no modo bin�rio
    FILE *arquivo = fopen(pessoasFile, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Vari�vel para armazenar um registro lido do arquivo
    tipopessoa pessoa;

    // Ler e imprimir todos os registros do arquivo
    while (fread(&pessoa, sizeof(tipopessoa), 1, arquivo) == 1) {
        printf("ID: %s\n", pessoa.id);
        printf("Nome: %s\n", pessoa.nome);
        printf("Email: %s\n", pessoa.email);
        printf("Senha: %s\n", pessoa.senha);
        printf("Sexo: %s\n", pessoa.sexo);
        printf("Data de nascimento: %d/%d/%d\n", pessoa.dia, pessoa.mes, pessoa.ano);
        printf("Cidade: %s\n", pessoa.cidade);
        printf("Estado: %s\n", pessoa.estado);
        printf("Pa�s: %s\n", pessoa.pais);
        printf("-----------------------------\n");
    }

    // Fechar o arquivo
    fclose(arquivo);
}

// Fun��o para ordenar os registros pelo nome
void ordenarPorNome(tipopessoa *inicio) {
    int num_registros = 0;
    tipopessoa *corrente = inicio;
    while (corrente != NULL) {
        num_registros++;
        corrente = corrente->next;
    }

    tipopessoa *registros = (tipopessoa *)malloc(num_registros * sizeof(tipopessoa));
    if (registros == NULL) {
        printf("Erro de aloca��o de mem�ria.\n");
        return;
    }

    corrente = inicio;
    for (int i = 0; i < num_registros; i++) {
        registros[i] = *corrente;
        corrente = corrente->next;
    }

    // Ordena��o simples usando bubble sort
    for (int i = 0; i < num_registros - 1; i++) {
        for (int j = 0; j < num_registros - i - 1; j++) {
            if (strcmp(registros[j].nome, registros[j + 1].nome) > 0) {
                tipopessoa temp = registros[j];
                registros[j] = registros[j + 1];
                registros[j + 1] = temp;
            }
        }
    }

    corrente = inicio;
    for (int i = 0; i < num_registros; i++) {
        *corrente = registros[i];
        corrente = corrente->next;
    }

    free(registros);
}

void InitialForm()
{
    if (inicio == NULL)
    {
        corrente = (tipopessoa*)malloc(sizeof(tipopessoa));
        inicio = corrente;
        auxiliar = corrente;
        corrente->next = NULL;
        corrente->back = NULL;
        fim=corrente;
        Enterdata();
    } else {
        corrente = (tipopessoa*)malloc(sizeof(tipopessoa));
        auxiliar->next = corrente;
        corrente->back = auxiliar;
        auxiliar = corrente;
        fim = corrente;
        corrente->next = NULL;
        Enterdata();
    }
}

void listarDadosUsuarioAtual(char *email, char *senha) {
    // Abrir o arquivo para leitura no modo bin�rio
    FILE *arquivo = fopen(pessoasFile, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Vari�vel para armazenar um registro lido do arquivo
    tipopessoa pessoa;

    // Ler e buscar o usu�rio atual no arquivo
    while (fread(&pessoa, sizeof(tipopessoa), 1, arquivo) == 1) {
        if (strcmp(pessoa.email, email) == 0 && strcmp(pessoa.senha, senha) == 0) {
            // Usu�rio encontrado, copiar os dados para o ponteiro corrente
            corrente = (tipopessoa*)malloc(sizeof(tipopessoa));
            *corrente = pessoa;
            printf("Dados do usu�rio atual copiados para o ponteiro corrente.\n");
            break; // Encerrar o loop ap�s encontrar o usu�rio
        }
    }

    if (corrente == NULL) {
        printf("Usu�rio n�o encontrado.\n");
    }

    // Fechar o arquivo
    fclose(arquivo);
}

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
 * Laço
 * If .. else
 * Modularização - OBRIGATORIO
 * Ponteiro
 * Vetores
 * Manipulação de string - OBRIGATORIO
 * Manipulação de Arquivos Texto - OBRIGATORIO
 * Registro - OBRIGATORIO
 * Manipulação de Arquivos Binarios - OBRIGATORIO
 * Lista Duplamente encadeada - OBRIGATORIO
*/

// Estrutura para armazenar informações de uma pessoa
typedef struct tipopessoa {
    int id[10];
    char nome[50];
    char sexo[2];
    char email[99];
    char senha[50];
    int dia[3];
    int mes[3];
    int ano[5];
    char cidade[10];
    char estado[3];
    char pais[10];
    struct tipopessoa *next, *back;
} tipopessoa;

// Estrutura para armazenar informações de uma Leaderboard
typedef struct {
    char nome[50];
    int pontos;
    char data[20]; // A data será armazenada como uma string no formato "dd/mm/aaaa"
} LeaderboardEntry;


// Variáveis globais para a lista de pessoas
struct tipopessoa *auxiliar, *auxiliar2, *corrente, *inicio, *fim;


// 1 = Cross | 2 = Circle | 0 = White
int game = 0,
    player = 0,
    machine = 0,
    end = 0,
    pontos =0,
    matrix[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
    };
char *leaderboardFile = "leaderboard.dat",
     *pessoasFile = "pessoas.dat";


void inserirNaLeaderboard(const char *nome, int pontos);
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
int verificarEmail(char email[99]);
int verificarSenha(char senha[50]);
int MaquinaJoga();
int Ganhou();

int main()
{
    setlocale(LC_CTYPE, "portuguese");// Configuração acento

    //inserirNaLeaderboard("João", 12);
    char email[99], senha[50];
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
                printf("\nUsuário e senha Válidados.\n");
                system("pause");
                auth = 1;
                break;
            }else{
                printf("\nUsuário e senha inválidos.\n");
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
                printf("\nUsuário e senha Válidados.\n");
                system("pause");
                auth = 1;
                break;
            }else{
                printf("\nUsuário e senha inválidos.\n");
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

        printf("\n Escolha a Opção: ");

        while (scanf("%d", &op) != 1)
        {
            printf("\nValor inválido. Insira um número inteiro: ");
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
            break;
        case 99:
            removerArquivosDat();
            break;
        default:
            printf("\n Função não encontrada.. tente novamente");
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
        printf("\nPrint o %s ganho desta vez!!!!\n", corrente->nome);
        EndGame();
    }
    else if (Ganhou() == 2)
    {
        machine++;
        end = 1;
        PrintGame(0);
        printf("\nPrint o Máquina ganhou desta vez!!!!\n");
        EndGame();
        MaquinaOptions();
    }

    int linha, coluna;
    PrintGame(1);

    printf("\nDigite o número da Linha: ");
    while (scanf("%d", &linha) != 1)
    {
        printf("\nValor inválido. Insira um número inteiro: ");
        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    PrintGame(2);
    printf("\nDigite o número da Coluna: ");
    while (scanf("%d", &coluna) != 1)
    {
        printf("\nValor inválido. Insira um número inteiro: ");
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
        printf("\nPrint o Máquina ganhou desta vez!!!!\n");
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
    // Implemente a lógica para a máquina decidir onde jogar
    // Retorna a posição na matriz onde a máquina quer jogar

    // Verificar se a máquina pode ganhar na próxima jogada
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = 2;
                if (Ganhou() == 2) {
                    matrix[i][j] = 0;
                    return i * 3 + j; // Retorna a posição da matriz
                }
                matrix[i][j] = 0;
            }
        }
    }

    // Verificar se o jogador pode ganhar na próxima jogada e bloquear
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][j] = 1;
                if (Ganhou() == 1) {
                    matrix[i][j] = 2;
                    return i * 3 + j; // Retorna a posição da matriz
                }
                matrix[i][j] = 0;
            }
        }
    }

    // Tentar jogar no centro se estiver vazio
    if (matrix[1][1] == 0) {
        return 4; // Retorna a posição da matriz
    }

    // Tentar jogar em um canto se estiver vazio
    int cantos[] = {0, 2, 6, 8};
    for (int i = 0; i < 4; i++) {
        int linha = cantos[i] / 3;
        int coluna = cantos[i] % 3;
        if (matrix[linha][coluna] == 0) {
            return cantos[i]; // Retorna a posição da matriz
        }
    }

    // Jogar em uma posição aleatória vazia
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                return i * 3 + j; // Retorna a posição da matriz
            }
        }
    }

    return -1; // Retorna -1 se não houver posição disponível (isso não deve acontecer)
}

void MaquinaOptions()
{
    int posicao = MaquinaJoga(); // Armazena a posição retornada por MaquinaJoga

    // Calcular o endereço do elemento na matriz usando ponteiro
    int linha = posicao / 3; // Calcula a linha da matriz
    int coluna = posicao % 3; // Calcula a coluna da matriz

    // Verificar se a posição está vazia
    printf("\nLinha: %i\n", linha);
    printf("\nColuna: %i", coluna);
    printf("\nposicao: %i\n", posicao);
    printf("\nTabela valor: %i", matrix[linha][coluna]);
    printf("\nse igual a 0: %i\n", matrix[linha][coluna] == 0);
    if (matrix[linha][coluna] == 0) {
        matrix[linha][coluna] = 2; // Marca a posição como ocupada pela máquina
    }

    // Após marcar a posição, imprimir as opções disponíveis
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
        pontos += 14 - soma + game;
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
        printf("\nPlacar do jogo %i\nJogador: %i\nMáquina: %i\nPontos do Jogador: %i\n", game, player, machine, pontos);
        printf("\nDeseja continuar?\n1: para sim\n2: para não\nDigite a opção: ");

        if (scanf("%d", &stop) != 1) {
            printf("Entrada inválida. Digite um número inteiro.\n");
            // Limpar o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        if (stop == 1 || stop == 2) {
            break;
        } else {
            printf("Opção inválida. Digite 1 ou 2.\n");
        }
    }

    if (stop == 2) {
        inserirNaLeaderboard(corrente->nome, pontos);
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

// Função de comparação para qsort
int compararPontuacao(const void *a, const void *b) {
    const LeaderboardEntry *pa = (const LeaderboardEntry *)a;
    const LeaderboardEntry *pb = (const LeaderboardEntry *)b;
    return pb->pontos - pa->pontos; // Ordenar em ordem decrescente
}

// Função para inserir dados de uma pessoa na leaderboard e salvar em um arquivo .dat
void inserirNaLeaderboard(const char *nome, int pontos) {
    // Criar uma instância da estrutura LeaderboardEntry
    LeaderboardEntry pessoa;

    // Copiar o nome e a pontuação fornecidos para a estrutura
    strncpy(pessoa.nome, nome, sizeof(pessoa.nome) - 1);
    pessoa.nome[sizeof(pessoa.nome) - 1] = '\0'; // Garantir que a string do nome está terminada
    pessoa.pontos = pontos;

    // Obter a data atual
    time_t t = time(NULL);
    struct tm *data_atual = localtime(&t);
    strftime(pessoa.data, sizeof(pessoa.data), "%d/%m/%Y", data_atual);

    // Abrir o arquivo para leitura e escrita no modo binário
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

// Função para recuperar os dados da leaderboard
void recuperarLeaderboard() {
    // Abrir o arquivo para leitura no modo binário
    FILE *arquivo = fopen(leaderboardFile, "rb");
    if (arquivo == NULL) {
        printf("Não tem ainda uma Leaderboard.\n");
        return;
    }

    // Variável para armazenar todos os registros
    LeaderboardEntry pessoas[100]; // Supondo um máximo de 100 registros

    // Variável para contar o número de registros lidos
    int num_registros = 0;

    // Ler cada registro do arquivo e armazenar na array de pessoas
    LeaderboardEntry pessoa;
    while (fread(&pessoa, sizeof(LeaderboardEntry), 1, arquivo) == 1) {
        pessoas[num_registros++] = pessoa;
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Ordenar as pessoas pelo número de pontos usando qsort
    qsort(pessoas, num_registros, sizeof(LeaderboardEntry), compararPontuacao);

    printf("=== Leaderboard Ordenada por Pontuação ===\n");
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
    scanf("%98s", &corrente->email);
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
        printf("\nValor inválido. Insira um número inteiro: ");
        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("\n Informe o Mês de nascimento: [12]: ");
    while (scanf("%d", &corrente->mes) != 1)
    {
        printf("\nValor inválido. Insira um número inteiro: ");
        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("\n Informe a Ano de nascimento: [1999]: ");
    while (scanf("%d", &corrente->ano) != 1)
    {
        printf("\nValor inválido. Insira um número inteiro: ");
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

    printf("\n Informe o nome do país: ");
    scanf("%9s", &corrente->pais);
    while (getchar() != '\n'); // Limpar o buffer de entrada
}

void salvarPessoa() {
    // Abrir o arquivo para escrita no modo binário
    FILE *arquivo = fopen(pessoasFile, "ab+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Ordenar os registros pelo nome antes de salvar
    ordenarPorNome(inicio);

    // Escrever os registros no arquivo
    tipopessoa pessoa;
    corrente = inicio;
    while (corrente != NULL) {
        pessoa = *corrente; // Copiar o conteúdo do nó atual para a variável pessoa
        fwrite(&pessoa, sizeof(tipopessoa), 1, arquivo);
        corrente = corrente->next;
    }

    // Fechar o arquivo
    fclose(arquivo);
}

int verificarEmail(char email[99]) {
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
    return 0; // Retornar 0 se o email não for encontrado
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
    return 0; // Retornar 0 se a senha não for encontrada
}

void editarDados(char *email, char *senha) {
    // Abrir o arquivo para leitura e escrita no modo binário
    FILE *arquivo = fopen(pessoasFile, "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Variável para armazenar um registro lido do arquivo
    tipopessoa pessoa;

    // Ler e buscar o usuário no arquivo
    while (fread(&pessoa, sizeof(tipopessoa), 1, arquivo) == 1) {
        if (strcmp(pessoa.email, email) == 0 && strcmp(pessoa.senha, senha) == 0) {
            // Usuário encontrado, permitir a edição dos dados
            printf("Digite os novos dados:\n");
            Enterdata(); // Função para inserir os novos dados

            // Posicionar o ponteiro do arquivo para a posição de escrita correta
            fseek(arquivo, -sizeof(tipopessoa), SEEK_CUR);

            // Escrever os novos dados no arquivo
            fwrite(&pessoa, sizeof(tipopessoa), 1, arquivo);

            printf("Dados do usuário editados com sucesso.\n");
            fclose(arquivo);
            return; // Sai da função após editar os dados
        }
    }

    printf("Usuário não encontrado.\n");
    fclose(arquivo);
}

void listarDadosUsuario(char *email, char *senha) {
    // Abrir o arquivo para leitura no modo binário
    FILE *arquivo = fopen(pessoasFile, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Variável para armazenar um registro lido do arquivo
    tipopessoa pessoa;

    // Ler e buscar o usuário atual no arquivo
    while (fread(&pessoa, sizeof(tipopessoa), 1, arquivo) == 1) {
        if (strcmp(pessoa.email, email) == 0 && strcmp(pessoa.senha, senha) == 0) {
            // Usuário encontrado, imprimir os dados
            printf("Nome: %s\n", pessoa.nome);
            printf("Email: %s\n", pessoa.email);
            printf("Senha: %s\n", pessoa.senha);
            printf("Sexo: %c\n", pessoa.sexo);
            printf("Data de nascimento: %s/%s/%s\n", pessoa.dia, pessoa.mes, pessoa.ano);
            printf("Cidade: %s\n", pessoa.cidade);
            printf("Estado: %s\n", pessoa.estado);
            printf("País: %s\n", pessoa.pais);
            printf("-----------------------------\n");
            fclose(arquivo);
            return;
        }
    }
    printf("Usuário não encontrado.\n");
    fclose(arquivo);
}

void listarTodosDados() {
    // Abrir o arquivo para leitura no modo binário
    FILE *arquivo = fopen(pessoasFile, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Variável para armazenar um registro lido do arquivo
    tipopessoa pessoa;

    // Ler e imprimir todos os registros do arquivo
    while (fread(&pessoa, sizeof(tipopessoa), 1, arquivo) == 1) {
        printf("Nome: %s\n", pessoa.nome);
        printf("Email: %s\n", pessoa.email);
        printf("Senha: %s\n", pessoa.senha);
        printf("Sexo: %s\n", pessoa.sexo);
        printf("Data de nascimento: %d/%d/%d\n", pessoa.dia, pessoa.mes, pessoa.ano);
        printf("Cidade: %s\n", pessoa.cidade);
        printf("Estado: %s\n", pessoa.estado);
        printf("País: %s\n", pessoa.pais);
        printf("-----------------------------\n");
    }

    // Fechar o arquivo
    fclose(arquivo);
}

// Função para ordenar os registros pelo nome
void ordenarPorNome(tipopessoa *inicio) {
    int num_registros = 0;
    tipopessoa *corrente = inicio;
    while (corrente != NULL) {
        num_registros++;
        corrente = corrente->next;
    }

    tipopessoa *registros = (tipopessoa *)malloc(num_registros * sizeof(tipopessoa));
    if (registros == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    corrente = inicio;
    for (int i = 0; i < num_registros; i++) {
        registros[i] = *corrente;
        corrente = corrente->next;
    }

    // Ordenação simples usando bubble sort
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
    // Abrir o arquivo para leitura no modo binário
    FILE *arquivo = fopen(pessoasFile, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Variável para armazenar um registro lido do arquivo
    tipopessoa pessoa;

    // Ler e buscar o usuário atual no arquivo
    while (fread(&pessoa, sizeof(tipopessoa), 1, arquivo) == 1) {
        if (strcmp(pessoa.email, email) == 0 && strcmp(pessoa.senha, senha) == 0) {
            // Usuário encontrado, copiar os dados para o ponteiro corrente
            corrente = (tipopessoa*)malloc(sizeof(tipopessoa));
            *corrente = pessoa;
            printf("Dados do usuário atual copiados para o ponteiro corrente.\n");
            break; // Encerrar o loop após encontrar o usuário
        }
    }

    if (corrente == NULL) {
        printf("Usuário não encontrado.\n");
    }

    // Fechar o arquivo
    fclose(arquivo);
}

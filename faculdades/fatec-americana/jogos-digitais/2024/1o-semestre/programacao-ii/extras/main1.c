#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

void PrintGame(int colunaLinha, int *player, int *machine, int *matrix[][])
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
                        switch(*matrix[i][k])
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
    printf("\nPlacar\nJogador: %i\nMaquina: %i\n", *player, *machine);
}

void PrintOptions(int *game, int *player, int *machine, int *end , int *matrix[][])
{
    if(Ganhou(&matrix) == 1)
    {
        *player++;
        *end = 1;
        printf("\nPrint o %s ganho desta vez!!!!\n", "Jogador");
        EndGame(&game, &player, &machine, &end, &matrix);

    } else if(Ganhou(&matrix) == 2)
    {
        *machine++;
        *end = 1;
        printf("\nPrint o Maquina ganho desta vez!!!!\n");
        EndGame(&game, &player, &machine, &end, &matrix);
        MaquinaOptions(&game, &player, &machine, &end, &matrix);
    }

    int linha, coluna;
    PrintGame(1, &player, &machine, &matrix);
    printf("\nDigite o número da Coluna: ");
    while (scanf("%d", &coluna) != 1) {
        printf("Valor inválido. Insira um número inteiro: ");
        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    PrintGame(2, &player, &machine, &matrix);
    printf("\nDigite o número da Linha: ");
    while (scanf("%d", &linha) != 1) {
        printf("Valor inv�lido. Insira um n�mero inteiro: ");
        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    if(*matrix[linha][coluna] == 0)
    {
        *matrix[linha][coluna] = 1;
    }
    else
    {
        PrintOptions(&game, &player, &machine, &end , &matrix);
    }
    EndGame();
    MaquinaOptions();

    system("CLS");

    PrintGame(0,&player, &machine, &matrix);
}

void MaquinaOptions(, int *end , int *matrix[3][3])
{
    int *ponteiro = &matrix[0][0];
    int random_number = rand() % 9;
    ponteiro += random_number;
    if(*ponteiro == 0)
    {
        *ponteiro = 2;
    }
    else{
        MaquinaOptions(&game, &player, &machine, &end, &matrix);
    }
    PrintOptions(&game, &player, &machine, &end , &matrix);
}

void EndGame(int *game, int *player, int *machine, int *end , int *matrix[3][3])
{
    int soma = 0;

    if(*end)
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = 0;
            }
        }
        *game++;
        *end=0;
        Continuar();
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma += *matrix[i][j];
        }
    }

    if(*game % 2 == 0){
        if(soma > 12)
        {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    *matrix[i][j] = 0;
                }
            }
            *game++;
            Continuar();
        }
    }
    else
    {
        if(soma > 11)
        {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    *matrix[i][j] = 0;
                }
            }
            *game++;
            Continuar();
            PrintOptions(&game, &player, &machine, &end , &matrix);
        }
    }
}

int Ganhou(int *matrix[3][3])
{
    if((*matrix[0][0]==*matrix[0][1]&&*matrix[0][0]==*matrix[0][2])||
       (*matrix[0][0]==*matrix[1][0]&&*matrix[0][0]==*matrix[2][0])||
       (*matrix[0][0]==*matrix[1][1]&&*matrix[0][0]==*matrix[2][2]))
    {
        return *matrix[0][0];
    }
    else if((*matrix[0][1]==*matrix[1][1]&&*matrix[0][1]==*matrix[2][1]))
    {
       return *matrix[0][1];
    }
    else if((*matrix[0][2]==*matrix[1][1]&&*matrix[0][2]==*matrix[2][0])||
            (*matrix[0][2]==*matrix[1][2]&&*matrix[0][2]==*matrix[2][2]))
    {
        return *matrix[0][2];
    }
    else if((*matrix[1][0]==*matrix[1][1]&&*matrix[1][0]==*matrix[1][2]))
    {
        return *matrix[1][0];
    }
    else if((*matrix[2][0]==*matrix[2][1]&&*matrix[2][0]==*matrix[2][2]))
    {
        return *matrix[2][0];
    }
    return 0;
}

void Continuar()
{
    int stop;
    printf("\nDeseja continuar?\n1: para sim\n2: para não\nDigite a opção: ");
    scanf("%d", &stop);
    if(stop == 2)
    {
        exit(0);
    }
}

void InitialForm()
{

}

int main()
{
    // 1 = Cross | 2 = Circle | 0 = White
    int game = 0, player = 0, machine = 0, end=0, matrix[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    setlocale(LC_ALL, "Portuguese");

    InitialForm();
    PrintOptions(&game, &player, &machine, &end , &matrix);
    return 0;

}

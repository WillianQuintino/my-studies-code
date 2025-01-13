#include <stdio.h>
#include <stdlib.h>

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

// 1 = Cross | 2 = Circle | 0 = White
int game = 0, player = 0, machine = 0, end=0, matriz[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};


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

void Line()
{
    printf("  ");
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
// Função de geração de quadrados
void PrintGame()
{
    HeadLine();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(j == 5)
            {
                printf("%i ", i);
            }
            else
            {
                printf("  ", i);
            }
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
                        switch(matriz[i][k])
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
            printf("\n");
        }
        if(i != 2)
        {
          Line();
        }
        printf("\n");
    }
    HeadLine();
    printf("\nPlacar\nJogador: %i\nMaquina: %i\n", player, machine);
}

void PrintOptions()
{
    if(Ganhou() == 1)
    {
        player++;
        end = 1;
        printf("\nPrint o %s ganho desta vez!!!!\n", "Jogador");
        EndGame();

    } else if(Ganhou() == 2)
    {
        machine++;
        end = 1;
        printf("\nPrint o Maquina ganho desta vez!!!!\n");
        EndGame();
        MaquinaOptions();
    }

    int linha, coluna;
    PrintGame(matriz);

    printf("\nDigite o número da Coluna: ");
    scanf("%d", &coluna);

    printf("\nDigite o número da Linha: ");
    scanf("%d", &linha);

    if(matriz[linha][coluna] == 0)
    {
        matriz[linha][coluna] = 1;
    }
    else
    {
        PrintOptions();
    }
    EndGame();
    MaquinaOptions();

    system("clear||cls");

    PrintGame(matriz);
}

void MaquinaOptions()
{
    int *ponteiro = &matriz[0][0];
    int random_number = rand() % 9;
    ponteiro += random_number;
    if(*ponteiro == 0)
    {
        *ponteiro = 2;
    }
    else{
        MaquinaOptions();
    }
    PrintOptions();
}

void EndGame()
{
    int soma = 0;

    if(end)
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matriz[i][j] = 0;
            }
        }
        game++;
        end=0;
        Continuar();
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma += matriz[i][j];
        }
    }

    if(game % 2 == 0){
        if(soma > 12)
        {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    matriz[i][j] = 0;
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
                    matriz[i][j] = 0;
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
    if((matriz[0][0]==matriz[0][1]&&matriz[0][0]==matriz[0][2])||
       (matriz[0][0]==matriz[1][0]&&matriz[0][0]==matriz[2][0])||
       (matriz[0][0]==matriz[1][1]&&matriz[0][0]==matriz[2][2]))
    {
        return matriz[0][0];
    }
    else if((matriz[0][1]==matriz[1][1]&&matriz[0][1]==matriz[2][1]))
    {
       return matriz[0][1];
    }
    else if((matriz[0][2]==matriz[1][1]&&matriz[0][2]==matriz[2][0])||
            (matriz[0][2]==matriz[1][2]&&matriz[0][2]==matriz[2][2]))
    {
        return matriz[0][2];
    }
    else if((matriz[1][0]==matriz[1][1]&&matriz[1][0]==matriz[1][2]))
    {
        return matriz[1][0];
    }
    else if((matriz[2][0]==matriz[2][1]&&matriz[2][0]==matriz[2][2]))
    {
        return matriz[2][0];
    }
    return 0;
}

void Continuar()
{
    int stop;
    printf("\nDeseja continuar?\n1: para sim\n2: para nao\nDigite a opção: ");
    scanf("%d", &stop);
    if(stop == 2)
    {
        exit(0);
    }
}

int main()
{
    PrintOptions();
    return 0;

}

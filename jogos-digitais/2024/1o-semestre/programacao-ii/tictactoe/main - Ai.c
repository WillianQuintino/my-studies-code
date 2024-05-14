#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void HeadLine() {
    printf("  ");
    for (int m = 0; m < 3; m++) {
        for (int l = 0; l < 14; l++) {
            if (l == 7) {
                printf("%d", m + 1);
            } else {
                printf(" ");
            }
        }
    }
    printf("\n");
}

void HeadCol(int j, int i) {
    if (j == 5) {
        printf(" %d ", i + 1);
    } else {
        printf("   ");
    }
}

void Line(int colunaLinha) {
    if (colunaLinha == 1) {
        printf("   ");
    }
    for (int l = 0; l < 14 * 3; l++) {
        printf("#");
    }
}

void Cross(int j, int l) {
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

void Circle(int j, int l) {
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

void White() {
    printf(".");
}

void PrintGame(int colunaLinha, int *player, int *machine, int matrix[3][3]) {
    if (colunaLinha == 2) {
        HeadLine();
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            if (colunaLinha == 1) {
                HeadCol(j, i);
            }
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 14; l++) {
                    if ((k == 0 && l == 13) || (k == 1 && (l == 0 || l == 13)) || (k == 2 && l == 0)) {
                        printf("#");
                    } else {
                        switch (matrix[i][k]) {
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
            if (colunaLinha == 1) {
                HeadCol(j, i);
            }
            printf("\n");
        }
        if (i != 2) {
            Line(colunaLinha);
        }
        printf("\n");
    }
    if (colunaLinha == 2) {
        HeadLine();
    }
    printf("\nPlacar\nJogador: %d\nMaquina: %d\n", *player, *machine);
}

int main() {
    // 1 = Cross | 2 = Circle | 0 = White
    int game = 0, player = 0, machine = 0, end = 0, matrix[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    setlocale(LC_ALL, "Portuguese");

    while (1) {
        system("cls");
        PrintGame(0, &player, &machine, matrix);

        int linha, coluna;
        printf("\nDigite o número da Coluna: ");
        scanf("%d", &coluna);
        printf("\nDigite o número da Linha: ");
        scanf("%d", &linha);

        if (matrix[linha - 1][coluna - 1] == 0) {
            matrix[linha - 1][coluna - 1] = 1;
        } else {
            printf("Posição já ocupada. Tente novamente.\n");
            system("pause");
            continue;
        }

        // Verificar se o jogador ganhou
        if (Ganhou(matrix) == 1) {
            player++;
            printf("\nParabéns, você ganhou esta rodada!\n");
        } else if (Ganhou(matrix) == 2) {
            machine++;
            printf("\nA máquina ganhou esta rodada.\n");
        } else if (Ganhou(matrix) == 0 && IsFull(matrix)) {
            printf("\nDeu velha nesta rodada.\n");
        }

        // Máquina joga
        int jogadaMaquina = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = 2;
                    if (Ganhou(matrix) == 2) {
                        jogadaMaquina = i * 3 + j;
                        break;
                    }
                    matrix[i][j] = 0;
                }
            }
        }

        if (jogadaMaquina == -1) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (matrix[i][j] == 0) {
                        jogadaMaquina = i * 3 + j;
                        break;
                    }
                }
            }
        }

        matrix[jogadaMaquina / 3][jogadaMaquina % 3] = 2;

        // Verificar se a máquina ganhou
        if (Ganhou(matrix) == 2) {
            machine++;
            printf("\nA máquina ganhou esta rodada.\n");
        } else if (Ganhou(matrix) == 0 && IsFull(matrix)) {
            printf("\nDeu velha nesta rodada.\n");
        }

        game++;
        printf("\nPlacar:\nJogador: %d\nMáquina: %d\n", player, machine);
        system("pause");
    }

    return 0;
}

int Ganhou(int matrix[3][3]) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) {
            if (matrix[i][0] == 1) {
                return 1;
            } else if (matrix[i][0] == 2) {
                return 2;
            }
        }
    }

    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) {
            if (matrix[0][i] == 1) {
                return 1;
            } else if (matrix[0][i] == 2) {
                return 2;
            }
        }
    }

    // Verificar diagonais
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
        if (matrix[0][0] == 1) {
            return 1;
        } else if (matrix[0][0] == 2) {
            return 2;
        }
    }

    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
        if (matrix[0][2] == 1) {
            return 1;
        } else if (matrix[0][2] == 2) {
            return 2;
        }
    }

    return 0;
}

int IsFull(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}
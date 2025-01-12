#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_CTYPE, "portuguese");// Configura��o acento

    //declara��o de Vari�vel
    int num;

    // Dados de Entrada
    printf ("Digite um n�mero: ");
    scanf ("%i", &num);

    for (int linha = 1; linha < num; linha++)
    {
        for (int ast = 0; ast < linha; ast++)
        {
            printf("*");
        }

        printf("\n");
    }


    return 0;
}

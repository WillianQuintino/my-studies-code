#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_CTYPE, "portuguese");// Configuração acento

    //declaração de Variável
    int num;

    // Dados de Entrada
    printf ("Digite um número: ");
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

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "portuguese");// Configuração acento

    int num, metade;

    //Entradas
    printf("Digite um número: ");
    scanf("%i", &num);

    metade = num/2;

    //1a metade
    for(int linha=1; linha<=metade; linha ++)
    {
        for(int ast=1; ast <= linha; ast++)
        {
            printf("*");
        }
        printf("\n");
    }

    for(int linha = num-metade; linha>=1; linha --)
    {
        for(int ast=1; ast <= linha; ast++)
        {
            printf("*");
        }
        printf("\n");
    }
}

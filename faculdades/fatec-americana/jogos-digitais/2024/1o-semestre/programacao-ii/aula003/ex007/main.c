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

    metade = num / 2;

    for(int i = 1; i <= num; i++)
    {
        for(int j = num; j >= num; j++)
        {
            printf("-");
        }
        printf("\n");
    }
}

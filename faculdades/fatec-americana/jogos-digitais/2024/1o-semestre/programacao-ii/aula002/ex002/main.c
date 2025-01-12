#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "portuguese");// Configuração acento

    int num;

    //Entradas
    printf("Digite um numero: ");
    scanf("%i", &num);

    // Imprimir linhas
    for (int linha=num; linha>=1; linha-=1)
    {
        //printf("%i", linha);
        // Imprimir asteriscos
        for(int ast=1; ast<=linha; ast++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

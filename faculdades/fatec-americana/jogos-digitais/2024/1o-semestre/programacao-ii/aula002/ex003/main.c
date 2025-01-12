#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "portuguese");// Configuração acento

    int num;

    printf("Digite um N�mero: ");
    scanf("%i", &num);

    //imprimir linhas
    for(int linha = num-1; linha >= 0; linha -= 1)
    {

        // PARTE 1 - Imprimir tracinhos
        for(int traco = 0; traco <= linha; traco++)
        {
            printf("-");
        }

        // PARTE 2 - Imprimir *
        printf("*");

        //PARTE 3 - Imprirmir -*
        //for(int traast = num-linha-1; traast >= 1; traast--)
        for(int conj = 1; conj<=num-linha-1; conj++)
        {
            printf("-*");
        }

        printf("\n");
    }
    return 0;
}

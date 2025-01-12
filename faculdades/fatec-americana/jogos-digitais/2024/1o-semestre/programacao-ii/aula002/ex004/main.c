#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    setlocale(LC_CTYPE, "portuguese");// Configuração acento

    int num;

    printf("Digite um número: ");
    scanf("%i", &num);

    //imprimir linhas

    return 0;
}

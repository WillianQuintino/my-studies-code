#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "portuguese");// Configuração acento
    
    int num;

    //Entradas
    printf("Digite um número: ");
    scanf("%i", &num);

    for (int linha = 0; linha >= num; linha++ ){
        if(linha == 1 || linha == num)
        {
            printf("O");
            for (int i = 0; i < count; i++)
            {
                print("-")
            }
            printf("O");
            printf("\n");
            
        }
    }


    return 0;
}

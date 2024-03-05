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

    for (int i = 0; i < num; i++ )
    {
        for (int j = 0; j <= num+1; j++)
        {
            if (i == 0 || i == num-1){
                if (j==0 || j == num+1)
                {
                    printf("O");
                }
                else if (i != 0 || i != num-1)
                {
                    printf("-");
                }
            } else {
                if (j==0 || j == num+1)
                {
                    printf("-");
                }
                else if (i != 0 || i != num-1)
                {
                    printf(" ");
                }
            }

        }
        printf("\n");
    }
}

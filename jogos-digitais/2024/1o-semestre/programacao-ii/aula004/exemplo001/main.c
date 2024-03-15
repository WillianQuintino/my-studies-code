#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#include <matematica.h>

//int potencial (int base, int expoente); // Protótipo da Função (Cópia do Cabeçalho da Função

int main (){

    setlocale(LC_CTYPE, "portuguese");// Configuração acento

    int num, exp, r;

    printf("Digite um numero: ");
    scanf("%i", &num);

    printf("Digite o expoente: ");
    scanf("%i", &exp);

    r = potencia(num, exp);

    printf("Resultado = %i", r);

    return 0;

}



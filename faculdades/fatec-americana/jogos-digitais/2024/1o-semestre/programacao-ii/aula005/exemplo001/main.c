#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#include <matematica.h>

//int potencial (int base, int expoente); // Prot�tipo da Fun��o (C�pia do Cabe�alho da Fun��o

int potencia (int base, int expoente) {

    int res = 1;

    for (int i = 1; i <= expoente; i++) {
        res = res * base;
    }

    return res;

}

int main (){

    setlocale(LC_CTYPE, "portuguese");// Configura��o acento

    int num, exp, r;

    printf("Digite um numero: ");
    scanf("%i", &num);

    printf("Digite o expoente: ");
    scanf("%i", &exp);

    r = potencia(num, exp);

    printf("Resultado = %i", r);

    return 0;

}



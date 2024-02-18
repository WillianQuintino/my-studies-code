#include <stdio.h>
#include <stdlib.h>
#include <locate.h>

int main(){

    setlocate(LC_CTYPE, "portuguese"); // Configuração acento

    //declaração de Variável
    int num;
    
    // Dados de Entrada
    printf ("Digite um umero:");
    scanf ("%i", &num);

    return 0;
}

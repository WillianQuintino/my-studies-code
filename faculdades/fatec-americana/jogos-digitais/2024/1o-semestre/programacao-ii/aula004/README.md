[🔝](../README.md)

# (08/03/2024) - Aula 4 - Modularização/Função

```c
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int potencial (int base, int expoente) {

    int res = 1;

    for (int i = 1, i <= expoente, i++) {
        res = res * base;
    }

    return res;

}

int main (){
    
    setlocale(LC_CTYPE, "portuguese");// Configuração acento

    int num, exp, r;

    printf("Digite um numero: ");
    scanf("%i", &num);

    printf("Digite o expoente: ");   
    scanf("%i", &exp);

    r = potencia(num, exp);

}
```

<img title="" src="file:///D:/Documents/code/fatec-americana/jogos-digitais/2024/1o-semestre/programacao-ii/aula004/funcao-exemplo.drawio.svg" alt="" width="650">

## Benefícios

1. Melhor gerenciamento de memória

2. Melhor organização do código

3. Facilidade de manutenção

4. Reuso (evito repetições)

## Código

[exemplo001]()

[Como fazer uma Biblioteca em C? | Profes](https://profes.com.br/MarceloPastorino/blog/como-fazer-uma-biblioteca-em-c)

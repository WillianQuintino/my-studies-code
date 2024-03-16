[🔝](../README.md)

# 26/02/2024 - Aula 002

## Exercício

Desenvolva um programa que permita a inserção de 5 elementos na lista e que esteja encadeado.

[Exercício 001](ex001/main.c)

## Modalidade de Ponteiros

A fim de memorizar as funcionalidades dos [Ponteiros] conforma abaixo:

### Ponteiro sentinela

São [Ponteiros] que permanece no inicio da estrutura servindo de referência ais demais [Ponteiros].
Caso ocorra a Perda deste Ponteiro na estrutura, perde-se o acesso aos dados.
Quanto ao nome deste Ponteiro sentinela adota-se por "Inicio".

### Ponteiro de Processamento

São [Ponteiros] responsáveis por alocação de endereço de memoria. Encadeamento entre os nós recuperação dos dados na lista, em fim são [Ponteiros] operacionais do programa. São conhecidos com "auxiliar e corrente".

### Ponteiro de Estrutura

São [Ponteiros] que fazem parte da [strutuct], ou seja, campo de tipo Ponteiro. Sua Finalidade é garantir a integridade da lista, garantindo o armazenamento do endereço do nó seguinte / anterior.
Conhecido pelo nome de "Next".

## Exemplo 003

```c copy
#include <stdio.h>
#include <stdlib.h>

typeof struct no
{
    int codigo;
    char nome[30]
    struct no *next;
}no;
struct no *auxiliar, *corrente, *inicio;

void Enterdata()
{
    printf("\n informe o codigo");
    scanf("%d", &corrente -> codigo);

    printf("\n informe o nome");
    scanf("%s", &corrente -> nome);
}

void insert()
{
    if (inicio == NULL)
    {
        corrente=(no*)malloc(sizeof(no));
        auxiliar=corrente;
        inicio=corrente;
        corrente->next=NULL;
        Enterdata();
    }
    else
    {
        corrente=(no*)malloc(sizeof(no));
        auxiliar -> next = corrente;
        corrente -> next = NULL;
        auxiliar = corrente;
        Enterdata();
    }
}
```
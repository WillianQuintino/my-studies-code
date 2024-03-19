[🔝](../README.md)

# 18/03/2024 - Aula 005

## Classificação por inserção

### I Etapa

- Alocar endereço ao Ponteiro;

- Fazer o carregamento dos dados ```Enterdata```;

- Estabelecer variáveis, caso julgue necessário;

### II Etapa

- Verificar se inicio é igual a ```NULL```, caso estabeleça o primeiro nó na memoria; 

### III Etapa

- Caso o primeiro nó, já esteja instalado, verifique se o nó, recém alocado, precede o primeiro nó, de memoria, fazer o procedimento que garanta a recuperação e a referência.

### IV Etapa

- Caso o nome seja maior que o nó instalado faça o sincronismo de Ponteiro, de forma a garantir que os ponteiro estejam posicionados para o fins de garantir o encadeamento do nó na lista.

### V Etapa

- inicie o looping para o posicionamento do nó no meio da Lista, utilizando comparação `if()`, caso não satisfaça a condição, salte os ponteiros, para fazer nova validação dos dados.

### VI Etapa

- Em caso do elemento não for inserido na lista, é devido ao fato do nome ser o ultimo elemento da lista.

[Exercício 001](ex001/main.c)

## Lista Duplamente Encadeada

A Lista Duplamente Encadeada é uma Lista sequencial que permite operacionalizar nos dois sentidos da Lista.

Para que possamos fazer esta navegação será necessário estabelecer o segundo ponteiro na Sctruct, conforme exemplo abaixo:



```c copy
typeof struct no
{
    int codigo;
    char nome[15];
    struct no *next, *back;
}no;
```

Conforme o lay-out do no teremos

[back][    ][next]

Em uma Lista Duplamente Encadeada temos dois Ponteiros Sentinela, Inicio/Fim.

I                        F
[z[] ]-[[]]-[[]]-[[]z]



**Exercício:**

Converta a estrutura simplesmente encadeada para duplamente encadeada.



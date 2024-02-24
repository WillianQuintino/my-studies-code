[🔝](../README.md)
# 19/02/2024 - Aula 001 - Apresentação do plano de ensino e Conceitos e Fudamentos.

## Plano de Ensino

1. Conceito e fundamentos;
2. Operações de ponteiro;
3. Funções de Ponteiro;
4. Tecnica de encadeamento;
5. Alocação de memoria;
6. Estrutura simples encadeada;
7. Estrutura duplamente encadeada;
8. Circular;
9. Pilha;
10. Notação Polonesa Reversa;
11. Fila;
12. Árvore;
13. Árvore Binária;
14. Técnica de hashing.

fread
fopen
    R -> começo do arquivo
final do arquivo feof

> [Estruturas de Dados com Jogos por Roberto Roberto Ferrari](https://www.amazon.com.br/Estruturas-Dados-Jogos-Roberto-Ferrari/dp/8535278044)

I Prova -> Peso 4 -> do 5 ao 8.
II Prova -> Peso 6 -> do 9 ao 14.
Sub -> substitui uma nota ->Toda a Materia.

## Variaves Dinamicas

> Todas as estrutura de dados vistas anteriomente são extáticas, isto é, as variáveis não pode ser modificadas, mesmo que seja pouco utilizado.
> Durante cada execução do programa, a quantidade de bytes alocados para as variáveis não pode ser modificadas, mesmo que seja pauco utilizado.
> É muito frequente, entretanto, a ocorrência de listas de dados que variam de tamanho.
> Por outrolado, se num mesmo programa precisamos processar duas matrizes, de grande ordem, pode não haver espaço de memória  osficiente.
> O ideal seria utilizar o espaço para uma delas, fazer as operações desejada e dispor desse espaço liberando para outra estrutura.

## Variaveis Dinâmicas

> As variaveis dinâmicas que veremos a seguir não são criadas em tempo de copilação isso significa que o copilador não faz alocação de memoria para as variáveis dinâmicas.
> Durante a execução do programa podemos alocar o espaço desejado ou dispor dele quando nescessario.
>As variaveis dinâmicas não são declaradas explicitamente na partes de declarações do programa, nem tem nome.
> A forma de se fazer referência a uma variável dinâmica é atravás da estrutura dinâmica. Essa variável é do tipo ponteiro.

### Ponteiro

> Os valores do tipo ponteiro são endereço, de memória das estruturas dinamicas.
> Uma variáveis do tipo Ponteiro é definido pelo simbolo *\** segundo do tipo da variável dinâmica que pode ser referenciada por esse ponteiro.
>Exemplo:

```C COPY
    int *A;
    char *nome;
    float* salario;

    type def struct no
    {
        int codigo;
        char nome[10];
        float salario;
    } no;

    struct no *A, *B, *C;
```

> A declaração acima aloca espaço de memoria somente para as variavel do tipo ponteiro ocupa 4 bytes de memoria.
> Observe que na declaração do tipo ponteiro é especificado o tipo de estrutura que pode ser apontador por uma variavel ponteiro no exemplo acima, uma variavel do tipo ponteiro, pode refêrenciar ou apontar para uma estrura do tipo nó.

![Esquema da declaração](esquema-declaracao.drawio)

> A declaração das variáveis, A, B, C, não é inicializada, isto é, nenhum valor é armazenado em A, B e C na memória, e não existe nenhum struct estabelecida na memória.
> Para criar/estavelecer uma referência é preciso obter uma certa quantidade de espaço de memória.
> No exemplo acima, o espaço necessário é o número de bytes que acomoda as váriaveis A, B e C.
> A locação desse espaço e a sua localização na memória são feitos pela execução de um procedimento chamado Malloc.
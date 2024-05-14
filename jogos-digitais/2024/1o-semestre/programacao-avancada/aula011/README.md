[🔝](../README.md)

# 06/05/2024 - Aula 010

## Árvore Binária

Uma arvore binária é uma de grau 2, isto é, árvore em que nenhum né tem mais que dois filhos além disso, numa árvore binária, destungue-se uma subárvores esquerda e uma direita.

Exempo

A     A
  /       \
 B         B

Arvore distitas
 (relação da vertice)

Conforme a figura representanda acima são considerada arvore distintas, em relaç~cao a vertice e a sua posição nula.

Quanto a sua estrutura, ou seja, struct referenciamos da mesma forma de Lista Duplament, conforme exemplo abaixo:

```c copy
 typedef struct nodo
 {
    int codigo;
    char nome[30];
    struct nodo *back, *next;
 } nodo;
 ```

Uma árvore Binária, possui também uma Raiz, semelhante ao ponteiro inicio das demais estruturas já avaliadas.

Quando a Raiz e Null, podemos dizes que a árvore é Nulla, ou seja, não há nenhum nodo de arvore.

Podemos representadas o nodo conforme abaixo:

## Arvore de Busca Binária

uma arvore de binária cuja a raiz armazena o item, r, raiz, dizemos que a arvore de busca binária ou ordenada se a regra abaixo for implementada:

- todo item armazenado na subárvore esquerda da Raiz é menor que a Raiz.
 - todo item armazenado na subárvore direita da Raiz, deverá ser maior que a Raiz;
 Uma organização  baseada nesta regra não é permitido vetores em duplicata como veremos:
|RA|Nome Endereço|
|:--:|:--:|
|001|Maria|
|==002==|Alga|
|003|Julia|
|==002==|Marcio|
|.||
|.||
|.||

Nesta organizar não é aceita, chave em duplicada.

Exemplo: Aplicado AB

![Arvore de Busca Binária](arvore-busca-binaria.svg)


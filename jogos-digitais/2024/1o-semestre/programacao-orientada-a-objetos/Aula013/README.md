[🔝](../README.md)

# 09/04/2024 - Aula 013 -

Prof. Perrotti
POO

## Arrays (Matrizes)

Arrays são coleção de dados de mesmo tipo, organizado em uma estrutura indexada. A posição de cada elemento é indicada por um índice. Podem ter uma ou mais dimensões. Para cada dimensão é necessário um conjunto de índices. Em Java, arrays são objetos e precisam ser construídos antes do uso. Pelo fato de serem objetos, os arrays contém internamento atributos e métodos. um atributo especialmente útil é o __Length__, que informa o comprimento (qtd de posições) no Array.

```java
int vet[];
```

```java
vet = new int[10];
vet[0]=20;
```

```java
for(int i=0; i < vet.Length; i++)
{
    ///
}
```

```java
int mat[][];
mat = new int[10][20];
mat[0] = new int[15];
mat[1] = new int[18];
```

```java
for(int i = 0; i < mat.Length; i++)
{
    for(int j=0; j < mat[i].Length; j++)
    {
        mat[i][j] = i+j;
    }
}
```

1) Declare uma matriz de duas dimensões e construa a matrix de modo que a primeira linha tenha uma coluna, a segunda duas colunas e assim por diante. Faça isso para 16 linhas. A seguir preencha o array com a seguinte equação:

```java
mij = (i+1)^2 + 2*j;
```
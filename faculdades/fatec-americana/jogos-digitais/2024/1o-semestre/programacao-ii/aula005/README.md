[🔝](../README.md)

# (15/03/2024) - Aula 5 - Revisão da Prova

## I Prova 15/04/2024

Questões da Prova

1. Quais as modalidade de Ponteiro que podemos associar nas estruturas vistas?

2. Um Ponteiro armazena que tipo de informações?

3. Como ocorre alocação de endereços de memória ao ponteiros, e de que forma ocorre o acesso aos dados de lista?

4. As Listas (Simples/Duplamente), podemos referenciar em que modelo gerencial computacional?

5. Quais operações permitidas em listas?

6. Como o compilador troca as variáveis dinâmicas em relação a estática.

7. Descreva semanticamente as formas de operacionalizar os ponteiros durante a execução:
   
   1. Saltar Ponteiro
   
   2. Deslocar Ponteiro
   
   3. Sincronismo de Ponteiro

8. Converta uma Lista duplamente Encadeada em circular.

9. Como podemos notar a diferença entre uma Lista Simplesmente e Duplamente Encadeada

10. Comando que aloca endereço ao um ponteiro.

```c copy
void insert()
{
    if (inicio == NULL)
    {
        corrente = (no*)malloc(sizeof(no));
        inicio = corrente;
        auxiliar = corrente;
        corrente->next = NULL;
        corrente->back = NULL;
        fim=corrente;
        Enterdata();
    } else {
        corrente = (no*)malloc(sizeof(no));
        auxiliar->next = corrente;
        corrente->back = auxiliar;
        auxiliar = corrente;
        fim = corrente;
        corrente->next = NULL;
        Enterdata();
    }
}
```

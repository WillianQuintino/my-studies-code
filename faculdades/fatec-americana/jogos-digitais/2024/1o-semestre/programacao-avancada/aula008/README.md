[🔝](../README.md)

# 22/04/2024 - Aula 008

```c
void Puch()
{
    if (topo === NULL)
    {
        topo = (no*)malloc(sizeof(no));
        topo->next=NULL;
        topo->back=NULL;
        auxiliar = topo;
        c++;
        Enterdata();
    } else {
        if(c>10)
        {
            printf("\n stack overdlow...");
            system("\n pause");
        } else {
            topo=(no*)malloc(sizeof(no));
            auxiliar->next = topo;
            topo->back=auxiliar;
            topo->next=Null;
            auxiliar=topo;
            c++;
            Enterdata();
        }
    }
}
void main()
{
    topo=Null;
    auxiliar=Null;
}
```

Normalmente se encontro a pilha com duplamente caldeada.

## Notação Polonesa Reversa

Surge em decorrência do lançamento do primeiro compilador entre os anos 60 a fim de atender uma comunidade de Pesquisadores.
Mas a comunidade não a prova o compilados divido a falha na elaboração das expressões matemáticas. Sabemos que as expressões se forma a partir de alguns simbulos

Em vista do problema levantado surgi um lógica Polones chamado Jan Łukasiewicz que estabeleceu três notações citada baixo:

infixa: A+B;
Posfixa: AB+;
Prefixa: +AB;

|infixa|Posfixa|
|:--:|:--:|
|a+b|abc-+|
|(a*(k-j))|akj-*|
|(w-k)+(y+o)|wk-y+o+|
|((a+b)*k)/j|ab+k*j/|

Regra:

Oprando -> copia para saida
Operador -> guarda na Pilha
parenteses de fechamento -> Descarrega um operador da pilha;
parantese de abertura -> ignora

|Simbolo|Ação            |Pilha|Saida |
|:--:|:-----------------:|:---:|:----:|
|(   |Ignora             |-.-  |      |
|(   |Ignora             |-.-  |      |
|A   |Copia              |-.-  |A     |
|+   |Guardar            |+    |A     |
|B   |Copia              |+    |AB    |
|)   |Descarrega de Pilha|-.-  |AB+   |
|*   |Guarda             |*    |AB+   |
|K   |Copia              |*    |AB+K  |
|)   |Descarrega de Pilha|-.-  |AB+K* |
|/   |Guarda             |/    |AB+K* |
|J   |Copia              |/    |AB+K*J|
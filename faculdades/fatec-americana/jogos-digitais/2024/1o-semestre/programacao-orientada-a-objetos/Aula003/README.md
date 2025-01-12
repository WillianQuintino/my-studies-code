[🔝](../README.md)

# 21/02/2024 - Aula 002 - Construtores, Declaração, Construtor Padrão e Operador new.

Prof. Perrotti
POO

[Apostila da Aula](../ApostilaPOO.pdf) - Pode ser usado impresso na prova.
[Wiki de POO](https://pooperrotti.fandom.com/pt-br/)

## Contrutores

> São metodos escpecializados na construção  de novos objetos. A pricipal função do construtor é deixar o obejeto em um estado válido para que possa ser utilizado logo após a contrução. Para isso, o construtor precisa preencher os atributos com valores válidos que são informados através dos parâmetros do construtor, quando são características Indicadores de estado quase sempre tem o seu valor inicial conecido e portando não precisam ser informados.

## Declaração

> Em java, um contrutor sempre tem o mesmo nome que a clase e não pode ter nenhum tipo de retorno declarado, nem memo void.

## Contrutor Padrão

> Toda classe precisa tem pelo menos um contrutor. Caso nenum construtor seja declarado explicitamente para a classe, o java irá ciar um contrutor padrão implícícito. Um construtor padrão não tem parametros e dexar todos os atributos com valores nulos.

## Operador new

> É o operador de instanciação do java. Precisa ser utilizado para cada objeto criado no programa tem como operando algum construtor de classe e como resultado a referencia ao objeto criado

**Ex:**

```java
    Pessoa p = new Pessoa ();
```

## Lição

> Faça um método que incremente as faltas e um que verifique se foi aprovado ou não. O aluno é aprovado se teve menos de 25% de faltas.

```java
    boolean Aprovado();
```

> Novo projeto: Escola
> Classe Aluno
> Nome, ra, qtdAula, faltas
> 
> ------------------------------
> 
> Façam, setters, getter, o construtor e um métodos que imprima tudo.
> Obs. Não faça setter p/ faltas.
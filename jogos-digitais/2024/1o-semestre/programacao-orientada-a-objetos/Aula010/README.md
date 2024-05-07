[🔝](../README.md)

# 26/03/2024 - Aula 010 -

Prof. Perrotti
POO

## Classes Abstratas

São classes que não podem ser instanciadas. Ou porque não tem definições suficientes para a construção de objetos, ou porque objetos dessas classes não tem função dentro do sistema.

Classes abstratas servem apenas para ser ancestrais de outras classes. Em java, a classe é declarada abstrata com o uso da palavra reservada <u>abstract</u>

![DiagramaClassAbstract](DiagramaClassAbstract.svg)

## Métodos Abstratos

São métodos que são declarados, mas não são implementados, ou seja, têm assinatura, mas não tem código.

Só podem ser declarados em classes abstratas. A implementação deve ser feita pelas classes descendentes. Quando uma classe descendente herdada métodos abstratos de uma classe ancestral, herda também a obrigação de implementar esses métodos fazendo uma sobreposição.

![DiagramaMethodAbstract](DiagramaMethodAbstract.svg)

**Classe e método Abstrata:**

```java
public abstract class Ancestral
{
    //
    //
    //
    public abstract void metodo();
    //
    //
    //
}
```

**Classe descendente:**

```java
public class Descendente extends Ancestral
{
    //
    //
    //
    @Override
    public void metodo()
    {
        //
        //
        //
    }
}
```

[Zoo](Zoo\src\zoo\Zoo.java)

[Zoo > Animal](Zoo\src\zoo\Animal.java)

[Zoo > Animal > Gato](Zoo\src\zoo\Gato.java)

[Zoo > Animal > Cachorro](Zoo\src\zoo\Cachorro.java)
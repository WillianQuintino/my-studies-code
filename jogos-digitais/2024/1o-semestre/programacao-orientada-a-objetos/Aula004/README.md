[🔝](../README.md)

# 05/03/2024 - Aula 003 - this

Prof. Perrotti
POO

## Referência [this]

> É uma referencia ai objeto que existe dentro de todos os objetos. Só pode ser acessada dentro da classe Através do [this] é possível acessar atributos e métodos em classes da mesma hierarquia.

```java copy
    Pessoa p = new Pessoa();
        // T
        //
    public class Pessoa
    {
        private string nome;
        //
        //
        //
        public void setNome(string nome)
        {
            this.nome = nome;
        }
    }
```

## exercicio

> Novo projeto: Empresa
> Classe: Vendedor.
> Atributos:
>   nome (string)
>   code (1 a 100)
>   porcentagem (double)
>   totalVendas (double)
> Métodos
> Construtor
> Setters e Getters
> public void vendeu(double valor)
>   acumula o valor no total de vendas
> public double salario()
>   calcula e refatora o salário
> public void hollerith()
>   Imprime tudo, inclusive o salário e depois zera o total de vendas.

[ex002 > Classe Empresa](Empresa/src/empresa/Empresa.java)
[ex002 > Classe Vendedor](Empresa/src/empresa/Vendedor.java)
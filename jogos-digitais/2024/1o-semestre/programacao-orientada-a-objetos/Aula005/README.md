[🔝](../README.md)

# 12/03/2024 - Aula 005

Prof. Perrotti
POO

## Sobreposição

Ocorre quando a classe descendente reescreve um método que já existe na classe ancestral usando a mesma [Assinatura]. Nesse caso, a versao descendente se sobrepõe (substitui) a versão ancestral.

## Assinatura

É o que identifica um método e o torna único no contexto onde é valido (a classe). A assinatura é composta pelo nome do método e pelo nome do método e pelo tipo, ordem e qtd de parâmetros.

**Exemplo:**

[Empresa2 > Empresa2.java](Empresa2/src/empresa2/Empresa2.java)
[Empresa2 > Funcionario.java](Empresa2/src/empresa2/Funcionario.java)
[Empresa2 > Pessoa.java](Empresa2/src/empresa2/Pessoa.java)
[Empresa2 > Vendedor.java](Empresa2/src/empresa2/Vendedor.java)

## Construtor de cópias (copu constructor)

É um construtor que constrói uma cópia de um objeto que já existe. Su único parâmetro éo objeto que será copiado.
O objeto copiado terá em seus atributos os mesmos valores que o objeto original.

**Exemplo:**

```java copy
    public class pessoa
    
    private string nome, cpf;
    
    public Pessoa (Pessoa P)
    {
        nome = p.nome;
        cpf = p.cpf;
    }

```

## Exercicios

[Exercícios e exemplos | Wiki Programação Orientada a Objeto](https://pooperrotti.fandom.com/pt-br/wiki/Exerc%C3%ADcios_e_exemplos)
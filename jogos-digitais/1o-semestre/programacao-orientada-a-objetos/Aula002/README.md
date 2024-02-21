# Aula 002 -  21/02/2024

Prof. Perrotti
POO

## Java

Foi criada OO. Java não da para trabalhar sem oriatada objeto. Maneira como ele copila, foi o que velocionou na liguagem. 

[Cod. Fonte] -> [Copilador] -> [Arq. Ext] -> [Execução]
             L> Interpretador 

Java não tem ponteiros como C. Java é criado na base de C como sua evoluxação

Tipos de dados é diferente

int é o único igual.

Inteiro é o única linguagem que ele entende.

número de conotação cientifica é conotada pelo 10  elevado

4.78135 * 10 ^ 5
mantissa * base ^ expoente

|Tipos|Descrição|Bytes|
|---|:-----------------:|-------|
|int|Inteiro com sinal|4 bytes|
|short||2 bytes|
|long||8 bytes|
|byte||1 bytes|
|char|Carácter ou inteiro sem sinal|2 bytes|
|boolean|valor lógico (true/false)|1 byte|
|float|ponto flutuante|4 bytes|
|duble|ponto flutuante de precisão dupla|8 bytes|

String não é um tipo mais uma classe. Não é possível uso de arrays de caracteres para strings.

## Classes e objetos

Classes contém um conjunto de definições que são aplicadas aos objetos construídos a partir delas. Todos os objetos construidos a partir da mesma classe, têm o mesmo conjunto de definições e o mesmo comportamento.

Essas definições incluem, os atributos dos objetos as ações que eles executam, os métodos que ativam ou controlam essas ações e a maneira com que os objetos são construídos.

### Método
É o que ativa ou controla uma ação do objeto. Pode existir vários métodos para a mesma ação mas cada ação exige pelo menos um método.

### Atributos
São informações reacionados ao objeto e que são inerentes ao objeto, ou seja, existem porque o objeto existe.

### Decalação de classes

#### Nível de acesso:

**public ->** sem restrição de acesso.
Pode ser acessada de qualquer ponto do programa. Uma classe pública precisa  estar decalarada em um arquivo com o mesmo nome que a classe e extensão *.java*. Cada arquivo *.java* só pode ter uma classe pública.

**omitido ->** Acesso padrão. Só é visível no pacote onde foi declarada.


```java copy
    public class NomeClasse
    {
        //Corpo da classe
        //Atributos
        //Construtores
        //Métodos.
    }
```

#### Níveis de acesso p/ atributos e métodos

**public ->** Sem restrição.
**omitido ->** Padrão.
**protect ->** Acesso no mesmo pacote e pelas clases descendentes.
**private ->** Só a própria classe acessa.
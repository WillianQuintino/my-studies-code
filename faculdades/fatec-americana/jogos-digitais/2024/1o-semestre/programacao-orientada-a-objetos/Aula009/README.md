## 05/03/2024 - Aula 009 - Exercício 6

Prof. Perrotti
POO

**[Exercícios e exemplos | Wiki Programação Orientada a Objeto | Fandom](https://pooperrotti.fandom.com/pt-br/wiki/Exerc%C3%ADcios_e_exemplos)**

**6) Classe Circulo (Projeto cartesiano)** Ainda no projeto Cartesiano, acrescente a classe **Circulo**. Esta classe é descendente da classe Ponto. Para esta representação, o circulo é descrito por um ponto (centro) e o raio (double). Implemente os três construtores de praxe: padrão, parametrizado e clone. Para o construtor padrão inicie o círculo com centro em (0,0) e raio 1.

Faça também os seguintes métodos públicos:

- **void assign(Circulo cl):** Copia o valor dos atributos de cl para os atributos do objeto.
- **void escale(double factor):** Faz o escalonamento do círculo pelo fator de escalonamento informado no parâmetro.
- **String toString ( ):** retorna uma representação do círculo em forma de string no formato "(cx,cy):raio".
- **public boolean isValid()**: Informa se o círculo é válido ou não. Para este método, um círculo é válido se o raio é maior que zero.
- **double perimeter( ):** retorna o perímetro do círculo.
- **double area( ):** retorna a área do círculo.



[Cartesiano](Cartesiano\src\cartesiano\Cartesiano.java)

[Cartesiano - Ponto](Cartesiano/src/cartesiano/Ponto.java)

[Cartesiano - Segmento](Cartesiano/src/cartesiano/Segmento.java)

[Cartesiano - Circulo](Cartesiano/src/cartesiano/Circulo.java)



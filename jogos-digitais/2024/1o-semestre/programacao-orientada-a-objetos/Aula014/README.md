[🔝](../README.md)

# 10/04/2024 - Aula 014 -

Prof. Perrotti
POO

## Arrays de Objetos

O tipo base de um array pode ser uma classe de objetos. Nesse caso, o array será uma coleção de variáveis de instância dessa classe , podendo conter instância dessa classe, e também instancias de qualquer classe descendente, já que um objeto de uma classe descendente também é instância de todas suas classes ancestrais. Levado ao extremo, se a classe que dá tipo ao array for a classe Object, o array poderá conter objetos de qualquer classe, já que todas são descendentes de Objetos.

```java
public class ListaPessoas
{
    private Pessoa Lista[];
    private int count;

    public ListaPessoas(int capMax)
    {
        Lista = new Pessoa[CapMax];
        count = 0;
    }

    public boolean Add(pessoa p)
    {
        if(count >= lista.length)
            return false;
        lista[count]=p;
        count++;
        return true;
    }

    public void Listagem()
    {
        for(int i=0; i<count; i++)
        {
            lista[i].hollerith();
        }
    } 
}
```

[ListaPessoas](Faculdade/src/faculdade/ListaPessoas.java)

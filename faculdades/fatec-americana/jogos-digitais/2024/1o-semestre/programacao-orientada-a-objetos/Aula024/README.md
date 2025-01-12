# Criação de novas classes de exceções

Para criar novas classes de exceções, basta criar classes descendentes de Exception(verificadas) ou de RuntimeExeption (Não-verificadas) e reescrever o métodos toString() para retornar a mensagem desejada Opcionalmente é possível criar construtores adicionais que irão receber informações que podem ser Acrecentadas na mensagem.

```java copy
public class CPFInvalido extends Exception
{
    @override
    public String toString()
    {
        return "CPF inválido!!!";
    }
}
```

```java copy
throw new Exeption("msg");
```

```java copy
public class CPFInvalido extends Exception
{
   
    public String msg;

    public CPFInvalido()
    {
        msg = "CPF inválido!!!";
    }

    @Override
    public String toString()
    {
        return msg;
    }
}
```

```java copy
public class CPFInvalido extends Exception
{
   
    public String msg;

    public CPFInvalido(String cpf)
    {
        msg = "O CPF "+ cpf +" é inválido!!!";
    }

    @Override
    public String toString()
    {
        return msg;
    }
}
```
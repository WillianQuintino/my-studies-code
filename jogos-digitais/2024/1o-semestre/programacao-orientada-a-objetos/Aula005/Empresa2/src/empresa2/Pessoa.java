/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package empresa2;

/**
 *
 * @author 040069
 */
public class Pessoa 
{
    private String nome, cpf;

    // Construtor
    //
    public Pessoa(String nome, String cpf) 
    {
        setNome(nome);
        setCpf(cpf);
    }

    // Setters
    //
    public final void setNome(String nome) 
    {
        if(nome.isBlank())
            System.out.println("Nome inválido.");
        else
            this.nome = nome;
    }

    public final void setCpf(String cpf) 
    {
        if(cpf.isBlank())
            System.out.println("CPF inválido.");
        else
            this.cpf = cpf;
    }

    // Getters
    //
    public String getNome() 
    {
        return nome;
    }

    public String getCpf() 
    {
        return cpf;
    }
    
    public double calcSalario()
    {
        return 0;
    }
    
    public void hollerith()
    {
        System.out.println("Nome: " + nome + '\n' +
                "CPF: " + cpf + '\n' +
               "Salário líquido: " + calcSalario());
    }
    
}

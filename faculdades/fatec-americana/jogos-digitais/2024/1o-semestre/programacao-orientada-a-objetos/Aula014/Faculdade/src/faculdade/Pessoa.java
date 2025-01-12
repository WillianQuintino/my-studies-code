/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package faculdade;

/**
 *
 * @author 040069
 */
public abstract class Pessoa 
{
    private String nome, rg;
    private int filhos;
    private double salario;
    private final double valorAux= 100;

    public Pessoa(String nome, String rg, int filhos, double salario) 
    {
        setNome(nome);
        setRg(rg);
        setFilhos(filhos);
        setSalario(salario);
    }
    
    // Setters
    //
    public final void setNome(String nome) 
    {
        if(!nome.isBlank())
            this.nome = nome;
    }

    public final void setRg(String rg) 
    {
        if(!rg.isBlank())
            this.rg = rg;
    }

    public final void setFilhos(int filhos) 
    {
        if(filhos >= 0)
            this.filhos = filhos;
    }

    public final void setSalario(double salario) 
    {
        if(salario > 0)
            this.salario = salario;
    }
    
    // getters
    //
    public String getNome() 
    {
        return nome;
    }

    public String getRg() 
    {
        return rg;
    }

    public int getFilhos() 
    {
        return filhos;
    }

    public double getSalario() 
    {
        return salario;
    }
    
    // Outros métodos
    //
    public abstract double calcularSalario();
    public abstract void zerarMes();
    
    public double auxilioProc()
    {
        return valorAux * filhos;
    }
    
    public void hollerith()
    {
        System.out.println("Nome: " + nome + "\n" +
                "RG: " + rg + "\n" +
                "Filhos: " + filhos + "\n" +
                "Auxílio procriação: " + auxilioProc() + "\n" +
                "Salario base: " + salario + "\n" +
                "Salário líquido: " + calcularSalario());
    }
    
}

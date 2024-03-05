/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package empresa;

/**
 *
 * @author 0040962323006
 */
public class Vendedor {
    
    //Atributos
    private String nome;
    private int cod;
    private double porcentagem, totalVendas;
    
    public Vendedor(String nome, int cod, double porcentagem)
    {
        setNome(nome);
        setCod(cod);
        setPorcentagem(porcentagem);
        
    }
    
    // Setters
    public final void setNome(String nome)
    {
        if(!nome.isBlank()) this.nome = nome;
        else System.out.println("Nome inválido!!!");
    }
    
    public final void setCod (int cod)
    {
        if(cod > 0 && cod < 100) this.cod = cod; 
        else System.out.println("Codigo inválido!!!");
    }
    
    public final void setPorcentagem(double porcentagem)
    {
        if(porcentagem > 0 && porcentagem < 100) this.porcentagem = porcentagem; 
        else System.out.println("Porcentagem inválido!!!");
    }
    
    // Getters
    public String getNome()
    {
        return nome;
    }
    
    public int getCod ()
    {
        return cod;
    }
    
    public double getPorcetagem()
    {
        return porcentagem;
    }
    
    public double getTotalVendas()
    {
        return totalVendas;
    }
    
    //Métodos
    public void vendeu(double valor)
    {
        //Acumula o valor no total de vendas
        totalVendas = valor + totalVendas;
    }
    
    public double salario()
    {
        //Calcula e refatora o salário
        
        return (totalVendas/100) * porcentagem;
        
    }
    
    public void hollerith()
    {
        // Imprime tudo, inclusive o salário e depois zera o total de vendas.
        System.out.println("Nome: " + nome);
        System.out.println("Código: " + cod);
        System.out.println("Porcentagem: " + porcentagem);
        System.out.println("Total de Vendas: " + totalVendas);
        System.out.println("Salário: " + salario());
    }
}

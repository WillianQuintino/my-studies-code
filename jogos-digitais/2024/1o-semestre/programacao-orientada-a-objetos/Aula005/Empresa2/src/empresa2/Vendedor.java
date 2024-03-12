/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package empresa2;

/**
 *
 * @author 040069
 */
public class Vendedor extends Pessoa
{
    private double comissao, vendas;

    public Vendedor(String nome, String cpf, double comissao) 
    {
        super(nome, cpf);
        setComissao(comissao);
        vendas= 0;
    }
    
    public void setComissao(double comissao) 
    {
        if(comissao <= 0)
            System.out.println("Comissão inválida.");
        else
            this.comissao = comissao;
    }

    public double getComissao() 
    {
        return comissao;
    }

    public double getVendas() 
    {
        return vendas;
    }
    
    public void vendeu(double valor)
    {
        vendas+= valor;
    }

    @Override
    public double calcSalario()
    {
        return vendas * comissao/100;
    }
    
    @Override
    public void hollerith()
    {
        super.hollerith();
        System.out.println("Comissão: " + comissao + '\n' +
                    "Total de vendas: " + vendas);
        
    }
    
    
    
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package faculdade;

/**
 *
 * @author 040069
 */
public class Funcionario extends Pessoa
{
    private int faltas;
    private final double valeCox= 42;

    public Funcionario(String nome, String rg, int filhos, double salario) 
    {
        super(nome, rg, filhos, salario);
        faltas= 0;
    }
    
    public void registraFalta()
    {
        faltas++;
    }
    
    @Override
    public double calcularSalario()
    {
        return getSalario() + valeCox + auxilioProc() - (getSalario()/20)*faltas;
    }
    
    @Override
    public void zerarMes()
    {
        faltas= 0;
    }    

    @Override
    public void hollerith()
    {
        super.hollerith();
        System.out.println("Faltas no mês: " + faltas);
    }
    
    
}

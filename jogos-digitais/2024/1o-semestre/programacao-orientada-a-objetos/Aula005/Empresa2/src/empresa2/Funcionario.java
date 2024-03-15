/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package empresa2;

/**
 *
 * @author 040069
 */
public class Funcionario extends Pessoa
{
    private double salario;
    private int faltas;

    
    public Funcionario(String nome, String cpf, double salario) 
    {
        super(nome, cpf);
        setSalario(salario);
        faltas= 0;
    }
    
    // Seter
    //
    public final void setSalario(double salario) 
    {
        if(salario <= 0)
            System.out.println("Salário inválido.");
        else
            this.salario = salario;
    }
    
    // Getters
    //
    public double getSalario() 
    {
        return salario;
    }

    public int getFaltas() 
    {
        return faltas;
    }
    
    // Outros métodos
    //
    public void faltou()
    {
        faltas++;
    }
    
    @Override
    public double calcSalario()
    {
        return salario - (salario/20)*faltas;
    }
    
    @Override
    public void hollerith()
    {
        super.hollerith();
        System.out.println("Salário bruto: " + salario + '\n' +
                "Faltas: " + faltas);
    }
    
}

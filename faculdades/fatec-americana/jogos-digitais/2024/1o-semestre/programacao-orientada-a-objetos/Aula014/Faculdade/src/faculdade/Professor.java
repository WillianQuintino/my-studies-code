/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package faculdade;

/**
 *
 * @author 040069
 */
public class Professor extends Pessoa
{
    private int qtdAulas;

    public Professor(String nome, String rg, int filhos, double salario) 
    {
        super(nome, rg, filhos, salario);
        qtdAulas= 0;
    }
    
    public void registraAulas(int qtd)
    {
        qtdAulas+= qtd;
    }
    
    @Override
    public void zerarMes()
    {
        qtdAulas= 0;
    }
    
    @Override
    public double calcularSalario()
    {
        return getSalario()*qtdAulas + auxilioProc();
    }
    
    @Override
    public void hollerith()
    {
        super.hollerith();
        System.out.println("Aulas ministradas: " + qtdAulas);
    }
    
}

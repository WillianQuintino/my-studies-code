/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package faculdade;

/**
 *
 * @author 040069
 */
public class Faculdade {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Professor p1= new Professor("Joca", "12345678-9", 2, 100);
        p1.registraAulas(100);
        p1.hollerith();
        
        System.out.println("--------------------------------");
        
        Funcionario f1 = new Funcionario("Zeca", "98765432-1", 3, 5000);
        f1.registraFalta();
        f1.registraFalta();
        f1.hollerith();
        
        System.out.println("--------------------------------");
        
        ListaPessoas lp = new ListaPessoas(10);
        lp.Add(f1);
        lp.Add(p1);
        lp.Listagem();
    }
    
}

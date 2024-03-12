/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package empresa2;

/**
 *
 * @author 040069
 */
public class Empresa2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Funcionario f1= new Funcionario("Jó", "12345-6", 10000);
        
        f1.faltou();
        
        f1.hollerith();
        System.out.println("");
        
        Vendedor v1= new Vendedor("Zé", "12345-3", 5);
        v1.vendeu(100000);
        v1.hollerith();
        
    }
    
}

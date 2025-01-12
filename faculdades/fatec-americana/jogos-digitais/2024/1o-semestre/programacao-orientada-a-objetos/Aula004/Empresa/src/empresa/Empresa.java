/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package empresa;

/**
 *
 * @author 0040962323006
 */
public class Empresa {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Vendedor v1 = new Vendedor("Willian", 50, 30.0);
        
        v1.vendeu(5000);
        v1.vendeu(3000);
        v1.vendeu(700);
        v1.vendeu(300);
        v1.hollerith();
    }
    
}

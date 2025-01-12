/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package zoo;

/**
 *
 * @author 040069
 */
public class Zoo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Cachorro cao= new Cachorro();
        
        cao.animalComFome();
        System.out.println("");
        Gato cat= new Gato();
        cat.animalComFome();
        
    }
    
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package cartesiano;

/**
 *
 * @author 040069
 */
public class Cartesiano {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
//        Ponto p1= new Ponto(10,20);
//        Ponto p2= new Ponto(5, 10);
//        
//        System.out.println(p1.equals(p2));
//        
//        p2.escale(2);
//        
//        System.out.println(p1.equals(p2));
        
//        Segmento s= new Segmento();
        
//        System.out.println(s);
        
//        s.desloc(10, 11);

//        System.out.println(s);
//        System.out.println(s.length());
        
//        s.escale(2);
        
//        System.out.println(s.length());
        
        Circulo cl = new Circulo();
        
        System.out.println(cl);
        
        cl.desloc(10, 5);
        
        cl.escale(2);
        
        System.out.println(cl);
        System.out.println(cl.area());
        System.out.println(cl.perimeter());

    }
    
}

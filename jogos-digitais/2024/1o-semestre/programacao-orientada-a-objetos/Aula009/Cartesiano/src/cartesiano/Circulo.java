/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package cartesiano;

/**
 *
 * @author 0040962323006
 */
public class Circulo extends Ponto{
    
    private double raio;
    
    public Circulo()
    {
        super();
        raio=1;
    }
    
    public Circulo(double x, double y, double raio)
    {
        super(x, y);
        this.raio = raio;
    }
    
    public Circulo(Circulo c)
    {
        super(c);
        raio= c.raio;
    }
    
    public void assign(Circulo cl)
    {
        //Copia o valor dos atributos de cl para os atributos do objeto.
        super.assign(cl);
        raio=cl.raio;
    }
    
    @Override
    public void escale(double factor)
    {
        //Faz o escalonamento do círculo pelo fator de escalonamento informado no parâmetro.
        super.escale(factor);
        raio*= factor;
    }
    
    public String toString()
    {
        //retorna uma representação do círculo em forma de string no formato "(cx,cy):raio".
        return super.toString()+ ": " + raio;
    }
    
    public boolean isValid()
    {
        // Informa se o círculo é válido ou não. Para este método, um círculo é válido se o raio é maior que zero.
        return raio>0;

    }
    
    public double perimeter(){
        //retorna o perímetro do círculo.
        return 2 * Math.PI * raio;
    }
    
    public double area()
    {
        // retorna a área do círculo.
        return Math.PI * raio * raio;
    }
    
    
    
    
}

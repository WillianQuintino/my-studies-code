/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package cartesiano;

/**
 *
 * @author 040069
 */
public class Ponto extends Object
{
   protected double x, y;  // coordenadas do ponto
 
   // Construtor padrão (não tem parâmetros).
   // Inicializa o ponto na origem do plano.
   //
   public Ponto(){
      x = 0;
      y = 0;
   }
 
   // Construtor parametrizado.
   // Inicializa o ponto com as coordenadas fornecidas nos parâmetros.
   //
   public Ponto(double vX, double vY){
      x = vX;
      y = vY;
   }
 
   // Copy constructor (Construtor clone ou de cópia).
   // Inicializa o ponto com as coordenadas de outro ponto já existente.
   //
   public Ponto(Ponto pt){
      x = pt.x;
      y = pt.y;
   }
 
   /////////////////////////////////////////////////////////////////
   /// Getters e Setters
 
   // Retorna o valor de x
   public double getX(){
      return x;
   }
 
   // Retorna o valor de y
   public double getY(){
      return y;
   }
 
   // Modifica o valor de x
   public void setX(double newX){
      x = newX;
   }
 
   // Modifica o valor de y
   public void setY(double newY){
      y = newY;
   }
 
   // Modifica o valor de x e y
   public void setXY(double newX, double newY){
      x = newX;
      y = newY;
   }
 
   // Copia os atributos de pt
   public void assign(Ponto pt){
      x = pt.x;
      y = pt.y;
   }
 
   ///////////////////////////////////////////////////////////
   /// Cálculos
 
   // Retorna o delta x em relação a vX
   public double deltaX(double vX){
      return vX - x;
   }
 
   // Retorna o delta y em relação a vY
   public double deltaY(double vY){
      return vY - y;
   }
 
   // Retorna a distancia do ponto até as coordenadas informadas
   public double distance(double posX, double posY){
      double dx = deltaX(posX);
      double dy = deltaY(posY);
      return Math.sqrt(dx*dx + dy*dy);
   }
   
   public double distance(Ponto pt)
   {
       return distance(pt.x, pt.y);
   }
   
   public double distance()
   {
       return distance(0, 0);
   }
   
 
   ///////////////////////////////////////////////////////////
   /// Transformações
 
   // Multiplica X e Y por um fator de escalonamento.
   public void escale(double factor){
      x *= factor;
      y *= factor;
   }
 
   // Desloca o ponto.
   public void desloc(double dX, double dY){
      x += dX;
      y += dY;
   }
   
   @Override
   public String toString()
   {
       return "(" + x + ", " + y + ")";
   }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 89 * hash + (int) (Double.doubleToLongBits(this.x) ^ (Double.doubleToLongBits(this.x) >>> 32));
        hash = 89 * hash + (int) (Double.doubleToLongBits(this.y) ^ (Double.doubleToLongBits(this.y) >>> 32));
        return hash;
    }

    @Override
    public boolean equals(Object obj) 
    {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        
        final Ponto other = (Ponto) obj;
        if (Double.doubleToLongBits(this.x) != Double.doubleToLongBits(other.x)) {
            return false;
        }
        return Double.doubleToLongBits(this.y) == Double.doubleToLongBits(other.y);
    }
   
   
 
} // classe Ponto
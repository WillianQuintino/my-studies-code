/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package faculdade;

/**
 *
 * @author 0040962323006
 */
public class ListaPessoas {
    private final Pessoa Lista[];
    private int count;

    public ListaPessoas(int capMax)
    {
        Lista = new Pessoa[capMax];
        count = 0;
    }
    
    public boolean Add(Pessoa p)
    {
        if(count >= Lista.length)
            return false;
        Lista[count]=p;
        count++;
        return true;
    }

    public void Listagem()
    {
        for(int i=0; i < count; i++)
        {
            Lista[i].hollerith();
            System.out.println("--------------------------------");
        }
    } 
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package zoo;

/**
 *
 * @author 040069
 */
public abstract class Animal 
{
    public abstract void somDoAnimal();
    
    public void animalComFome()
    {
        somDoAnimal();
        somDoAnimal();
        somDoAnimal();
    }
    
}

package semaforos;

import java.util.concurrent.Semaphore;
/**
 *
 * @author HP
 */
public class Usuario extends Thread{
    private Semaphore sem;
    private String nombre;
    
 
    Usuario(Semaphore sem, String nombre){
        this.sem=sem;
        this.nombre=nombre;
    }
     public void run() {
        try {
                // Pídele permiso al semáforo para pasar 
                System.out.println(nombre+"Quiere entrar a imprimir");
                sem.acquire();
                System.out.println(nombre + " Empieza a imprimir");
                
                // El filósofo come
                Thread.sleep(300);
                
                System.out.println(nombre + " Ha terminado de imprimir");
                sem.release();
                
                // El Filósofo se va, dejando espacio para otros.
                Thread.sleep(300);
            }
        catch (InterruptedException e) {
            System.out.println("¡Algo salió mal!");
        }
    }
     
      public static void main(String[] args) {
          System.out.println("Se abre el ciber!");
        // Semáforo que permite 2 filósofos a la vez en la mesa
        Semaphore sem = new Semaphore(1);
        
        // Crear y arrancar los 5 filósofos
        new Usuario(sem, "Andres").start();
        new Usuario(sem, "Platón").start();
        new Usuario(sem, "Aristóteles").start();
        new Usuario(sem, "Confucio").start();
        new Usuario(sem, "Tales").start();
        
        
      }


}

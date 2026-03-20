package ejercicio.hilos;

public class EjercicioHilos extends Thread{
    EjercicioHilos(String nombreHilo){
        super(nombreHilo);
    }
    
    @Override
    public void run(){
        for(int i=0; i<10; i++)
            System.out.println(i+" - "+ getName());
        System.out.println("Hilo finalizado");
    }
    
    public static void main(String[] args) {
    new EjercicioHilos("Andres").start();
    new EjercicioHilos("Anula").start();
}
}


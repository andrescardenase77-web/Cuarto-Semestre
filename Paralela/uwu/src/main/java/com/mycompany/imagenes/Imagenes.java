package com.mycompany.imagenes;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

/**
 * Clase principal que gestiona los hilos.
 */
public class Imagenes {

    public static void main(String[] args) {
        // CONFIGURACIÓN
        // Asegúrate de tener esta carpeta creada con imágenes adentro, o cambia "." para leer la raíz
        String rutaEntrada = "C:/Users/pc/Downloads/PDI-concurrente-master/PDI-concurrente-master/img";
        String rutaSalida = "C:/Users/pc/Downloads/PDI-concurrente-master/PDI-concurrente-master/img_blanco_negro";
        int limiteImagenes = 25;

        File carpetaEntrada = new File(rutaEntrada);
        File carpetaSalida = new File(rutaSalida);

        // 1. Validar carpeta de entrada
        if (!carpetaEntrada.exists() || !carpetaEntrada.isDirectory()) {
            System.out.println("Error: La carpeta de entrada '" + rutaEntrada + "' no existe.");
            // Para pruebas rápidas, si no tienes carpeta, descomenta abajo para usar la raíz:
            // carpetaEntrada = new File("."); 
            return;
        }

        // 2. Crear carpeta de salida si no existe
        if (!carpetaSalida.exists()) {
            if (carpetaSalida.mkdir()) {
                System.out.println("Carpeta creada: " + rutaSalida);
            }
        }

        // 3. Obtener lista de archivos
        File[] archivos = carpetaEntrada.listFiles((dir, name) -> {
            String lower = name.toLowerCase();
            return lower.endsWith(".jpg") || lower.endsWith(".png") || lower.endsWith(".jpeg");
        });

        if (archivos == null || archivos.length == 0) {
            System.out.println("No se encontraron imágenes en " + rutaEntrada);
            return;
        }

        System.out.println("Se encontraron " + archivos.length + " imágenes. Procesando máximo " + limiteImagenes + "...");

        // Lista para guardar referencias a los hilos y poder hacer join() luego
        List<Thread> listaHilos = new ArrayList<>();
        long inicio = System.nanoTime();

        // 4. Crear y lanzar hilos (Uno por imagen, hasta 25)
        int procesados = 0;
        for (File archivo : archivos) {
            if (procesados >= limiteImagenes) break;

            // Instanciamos el Runnable con el archivo y la carpeta de destino
            Thread hilo = new Thread(new FiltroGris(archivo, carpetaSalida));
            listaHilos.add(hilo);
            hilo.start();
            
            procesados++;
        }

        // 5. Esperar a que terminen todos
        for (Thread t : listaHilos) {
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        long fin = System.nanoTime();
        System.out.println("--------------------------------------------------");
        System.out.println("Proceso finalizado.");
        System.out.println("Imágenes procesadas: " + procesados);
        System.out.println("Tiempo total: " + (fin - inicio) / 1_000_000 + " ms");
    }
}
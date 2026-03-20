/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package procesamientosecuencial;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

/**
 *
 * @author HP
 */
public class ProcesamientoSecuencial {

    // Carpetas de entrada y salida definidas en el laboratorio
    private static final String CARPETA_ENTRADA = "imagenes";
    private static final String CARPETA_SALIDA = "imagenes_grises_secuencial";

    public static void main(String[] args) {
        // 1. Preparación del entorno (Crear carpeta de salida si no existe)
        File directorioEntrada = new File(CARPETA_ENTRADA);
        File directorioSalida = new File(CARPETA_SALIDA);

        if (!directorioEntrada.exists() || !directorioEntrada.isDirectory()) {
            System.out.println("Error: La carpeta '" + CARPETA_ENTRADA + "' no existe. Por favor créala y agrega imágenes.");
            return;
        }
        if (!directorioSalida.exists()) {
            directorioSalida.mkdir();
        }

        // Obtener lista de archivos de imagen
        File[] archivos = directorioEntrada.listFiles((dir, name) -> 
            name.toLowerCase().endsWith(".jpg") || 
            name.toLowerCase().endsWith(".png") || 
            name.toLowerCase().endsWith(".jpeg")
        );

        if (archivos == null || archivos.length == 0) {
            System.out.println("No se encontraron imágenes en la carpeta de entrada.");
            return;
        }

        System.out.println("Iniciando procesamiento secuencial de " + archivos.length + " imágenes...");

        // ---------------------------------------------------------
        // LITERAL C: Medir el tiempo de ejecución total
        // ---------------------------------------------------------
        long inicioTotal = System.nanoTime();

        // ---------------------------------------------------------
        // LITERAL B: Recorrer y procesar cada imagen de la carpeta
        // ---------------------------------------------------------
        for (File archivo : archivos) {
            try {
                procesarImagenIndividual(archivo, directorioSalida);
            } catch (Exception e) {
                System.err.println("Error procesando " + archivo.getName() + ": " + e.getMessage());
            }
        }

        long finTotal = System.nanoTime();
        // ---------------------------------------------------------

        long tiempoTotalMs = (finTotal - inicioTotal) / 1_000_000;
        double tiempoTotalSeg = tiempoTotalMs / 1000.0;
        System.out.println("\nProcesamiento finalizado.");
        System.out.println("Imágenes procesadas: " + archivos.length);
        System.out.println("Tiempo TOTAL de ejecución secuencial: " + tiempoTotalMs + " ms");
        System.out.println("Tiempo TOTAL en segundos: " + String.format("%.2f", tiempoTotalSeg) + " s");
    }

    /**
     * LITERAL A: Lógica para procesar una sola imagen, convertirla y guardarla.
     * Se basa en el código proporcionado utilizando manipulación de bits.
     */
    private static void procesarImagenIndividual(File archivoEntrada, File directorioSalida) throws IOException {
        // Cargar la imagen
        BufferedImage imagen = ImageIO.read(archivoEntrada);
        if (imagen == null) return;

        int ancho = imagen.getWidth();
        int alto = imagen.getHeight();

        // Recorrer píxeles (Lógica de conversión a escala de grises)
        for (int y = 0; y < alto; y++) {
            for (int x = 0; x < ancho; x++) {
                int pixel = imagen.getRGB(x, y);

                // Extraer componentes usando bitwise shifting (como en tu código base)
                int alpha = (pixel >> 24) & 0xff;
                int red   = (pixel >> 16) & 0xff;
                int green = (pixel >> 8) & 0xff;
                int blue  = pixel & 0xff;

                // Promedio simple
                int gris = (red + green + blue) / 3;

                // Reconstruir el pixel gris
                int nuevoPixel = (alpha << 24) | (gris << 16) | (gris << 8) | gris;

                imagen.setRGB(x, y, nuevoPixel);
            }
        }

        // Guardar la imagen resultante
        String nombreSalida = "gris_" + archivoEntrada.getName();
        File archivoSalida = new File(directorioSalida, nombreSalida);
        
        // Detectar formato original o usar PNG por defecto
        String formato = "png";
        if(archivoEntrada.getName().toLowerCase().endsWith("jpg") || archivoEntrada.getName().toLowerCase().endsWith("jpeg")) {
            formato = "jpg";
        }
        
        ImageIO.write(imagen, formato, archivoSalida);
        // Opcional: Imprimir progreso individual (puede afectar ligeramente el tiempo si son muchas imágenes)
        // System.out.println("Procesada: " + archivoEntrada.getName());
    }
}

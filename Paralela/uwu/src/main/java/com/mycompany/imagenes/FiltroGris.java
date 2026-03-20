package com.mycompany.imagenes;

import java.awt.image.BufferedImage;
import java.io.File;
import javax.imageio.ImageIO;

/**
 * Hilo que toma un archivo de imagen, lo convierte a gris y lo guarda.
 */
public class FiltroGris implements Runnable {
    
    private final File archivoEntrada;
    private final File carpetaSalida;

    // Constructor: Recibe el archivo físico y dónde guardarlo
    public FiltroGris(File archivoEntrada, File carpetaSalida) {
        this.archivoEntrada = archivoEntrada;
        this.carpetaSalida = carpetaSalida;
    }

    @Override
    public void run() {
        try {
            // 1. Leer la imagen desde el disco
            // Hacemos esto DENTRO del hilo para paralelizara la lectura también
            BufferedImage imagen = ImageIO.read(archivoEntrada);
            
            if (imagen == null) {
                System.out.println("No se pudo leer la imagen: " + archivoEntrada.getName());
                return;
            }

            int ancho = imagen.getWidth();
            int alto = imagen.getHeight();

            // 2. Procesar la imagen completa (blanco y negro)
            for (int y = 0; y < alto; y++) {
                for (int x = 0; x < ancho; x++) {
                    int pixel = imagen.getRGB(x, y);

                    int rojo = (pixel >> 16) & 0xff;
                    int verde = (pixel >> 8) & 0xff;
                    int azul = pixel & 0xff;

                    int gris = (rojo + verde + azul) / 3;
                    int nuevoPixel = (gris << 16) | (gris << 8) | gris;

                    imagen.setRGB(x, y, nuevoPixel);
                }
            }

            // 3. Guardar la imagen en la nueva carpeta
            // Usamos el mismo nombre del archivo original
            File archivoSalida = new File(carpetaSalida, archivoEntrada.getName());
            
            // Guardamos como PNG o JPG (extraemos la extensión o forzamos png)
            ImageIO.write(imagen, "png", archivoSalida);
            
            System.out.println("Hilo " + Thread.currentThread().getId() + " terminó: " + archivoEntrada.getName());

        } catch (Exception e) {
            System.out.println("Error procesando " + archivoEntrada.getName());
            e.printStackTrace();
        }
    }
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

#define N 1000000
#define GRADO 3
#define REPETICIONES 25

#define FILAS (GRADO + 1)
#define COLS  (GRADO + 2)

double x[N];
double y[N];

/* Eliminación Gaussiana */
void resolver(int n, double A[][COLS], double X[]) {
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            double t = A[k][i] / A[i][i];
            for (int j = 0; j <= n; j++) {
                A[k][j] -= t * A[i][j];
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        X[i] = A[i][n];
        for (int j = i + 1; j < n; j++) {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }
}

int main() {

    srand((unsigned int)time(NULL));

    int nucleos = omp_get_num_procs();
    omp_set_num_threads(nucleos);

    printf("Nucleos usados: %d\n", nucleos);
    printf("Numero de datos: %d\n\n", N);

    /* Generación de datos */
    for (int i = 0; i < N; i++) {
        x[i] = ((double)rand() / RAND_MAX) * 10.0;
        y[i] = ((double)rand() / RAND_MAX) * 50.0;
    }

    /* Abrir CSV en modo append */
    FILE* archivo = fopen("tiempos.csv", "a");
    if (!archivo) {
        printf("Error al abrir tiempos.csv\n");
        return 1;
    }

    /* Escribir cabecera solo si el archivo está vacío */
    fseek(archivo, 0, SEEK_END);
    if (ftell(archivo) == 0) {
        fprintf(archivo, "numero_datos,tipo,numero_muestra,tiempo_segundos\n");
    }

    /* Repeticiones paralelas */
    for (int rep = 0; rep < REPETICIONES; rep++) {

        double sumas_x[2 * GRADO + 1] = { 0.0 };
        double sumas_xy[GRADO + 1] = { 0.0 };

        double inicio = omp_get_wtime();

#pragma omp parallel for \
        reduction(+: sumas_x[0 : 2 * GRADO + 1]) \
        reduction(+: sumas_xy[0 : GRADO + 1])
        for (int i = 0; i < N; i++) {

            double val_x = x[i];
            double val_y = y[i];

            double potencia_x = 1.0;
            for (int p = 0; p <= 2 * GRADO; p++) {
                sumas_x[p] += potencia_x;
                potencia_x *= val_x;
            }

            double potencia_xy = val_y;
            for (int p = 0; p <= GRADO; p++) {
                sumas_xy[p] += potencia_xy;
                potencia_xy *= val_x;
            }
        }

        int n = GRADO + 1;
        double Matriz[FILAS][COLS];
        double Resultado[FILAS];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Matriz[i][j] = sumas_x[i + j];
            }
            Matriz[i][n] = sumas_xy[i];
        }

        resolver(n, Matriz, Resultado);

        double tiempo = omp_get_wtime() - inicio;

        fprintf(archivo, "%d,Paralelo,%d,%.6f\n", N, rep + 1, tiempo);
        printf("Paralelo [%2d] -> %.6f s\n", rep + 1, tiempo);
    }

    fclose(archivo);

    printf("\nDatos agregados correctamente a tiempos.csv\n");

    return 0;
}

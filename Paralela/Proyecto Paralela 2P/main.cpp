#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h> // Necesario para OpenMP

// --- CONFIGURACIÓN DEL PROBLEMA ---
#define N 5000000
#define GRADO 3

// Constantes para dimensiones de matrices
#define FILAS (GRADO + 1)
#define COLS  (GRADO + 2)

// --- ARREGLOS GLOBALES ---
double x[N];
double y[N];

// Función Gauss-Jordan
void resolver(int n, double A[][COLS], double X[]) {
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            double t = A[k][i] / A[i][i];
            for (int j = 0; j <= n; j++) A[k][j] -= t * A[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        X[i] = A[i][n];
        for (int j = i + 1; j < n; j++) X[i] -= A[i][j] * X[j];
        X[i] /= A[i][i];
    }
}

int main() {
    srand(time(NULL));
    //Detectamos el total de nucleos
    int hardware_total = omp_get_num_procs();
    int hilos_a_usar = hardware_total;

    // Validación de seguridad (mínimo 1 hilo)
    if (hilos_a_usar < 1) hilos_a_usar = 1;

    // Configuramos el numero de hilos
    omp_set_num_threads(hilos_a_usar);

    printf("--- CONFIGURACION DE PARALELISMO ---\n");
    printf("Nucleos detectados en PC: %d\n", hardware_total);
    printf("Hilos configurados para esta ejecucion: %d\n", hilos_a_usar);
    printf("------------------------------------\n\n");

    printf("--- INICIO PROYECTO: REGRESION POLINOMIAL ---\n");
    printf("Procesando %d datos...\n", N);

    // 1. GENERACIÓN DE DATOS
    for (int i = 0; i < N; i++) {
        x[i] = ((double)rand() / RAND_MAX) * 10.0;
        y[i] = ((double)rand() / RAND_MAX) * 50.0;
    }

    // ==========================================
    // INICIO DE LA MEDICIÓN DE TIEMPO
    // ==========================================
    double start_time = omp_get_wtime();

    // 2. PREPARAR ACUMULADORES
    double sumas_x[2 * GRADO + 1];
    double sumas_xy[GRADO + 1];

    for (int i = 0; i <= 2 * GRADO; i++) sumas_x[i] = 0.0;
    for (int i = 0; i <= GRADO; i++)     sumas_xy[i] = 0.0;

    // 3. SECCIÓN CRÍTICA PARALELIZADA
    // La directiva usará el número de hilos que configuramos con omp_set_num_threads

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

    // 4. CONSTRUCCIÓN DE LA MATRIZ
    int n = GRADO + 1;
    double Matriz[FILAS][COLS];
    double Resultado[FILAS];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Matriz[i][j] = sumas_x[i + j];
        }
        Matriz[i][n] = sumas_xy[i];
    }

    // 5. RESOLVER EL SISTEMA
    resolver(n, Matriz, Resultado);

    // ==========================================
    // FIN DE LA MEDICIÓN DE TIEMPO
    // ==========================================
    double end_time = omp_get_wtime();
    double tiempo_total = end_time - start_time;

    // --- MOSTRAR RESULTADOS ---
    printf("\n>>> RESULTADOS <<<\n");
    printf("Tiempo de Ejecucion: %.6f segundos\n", tiempo_total);

    // Speedup estimado (Solo informativo, asumiendo que 1 hilo es la base)
    // Nota: Para un speedup real, debes correr primero con 1 hilo, anotar el tiempo y comparar manualmente.

    printf("Ecuacion de ajuste (Grado %d):\n", GRADO);
    printf("y = ");
    for (int i = 0; i <= GRADO; i++) {
        printf("(%.4f)x^%d ", Resultado[i], i);
        if (i < GRADO) printf("+ ");
    }
    printf("\n");

    return 0;
}

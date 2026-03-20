#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define N 100

#define NUM_HILOS 8

float datos[N];

typedef struct {
    int inicio;
    int fin;
    int operacion;
} Tarea;
DWORD WINAPI procesar(LPVOID arg) {
    Tarea* t = (Tarea*)arg;
    for (int i = t->inicio; i <= t->fin; i++) {
        switch (t->operacion) {
        case 0: datos[i] = log10f(datos[i]); break;
        case 1: datos[i] = log(datos[i]); break;
        case 2: datos[i] = cos(datos[i]); break;
        case 3: datos[i] = sin(datos[i]); break;
        case 4: datos[i] = sqrt(datos[i]); break;
        case 5: datos[i] = datos[i] * datos[i]; break;
        case 6: datos[i] = datos[i] - (N / NUM_HILOS); break;
        case 7: datos[i] = datos[i] + (N / NUM_HILOS); break;
        }
    }
    return 0;
}
int main() {
    HANDLE hilos[NUM_HILOS];
    Tarea tareas[NUM_HILOS];
    DWORD tiempoInicio, tiempoFin, tiempoTotal;
    for (int i = 0; i < N; i++)
        datos[i] = (float)(i + 1);
    int rep = 0;
    printf("Datos sin procesar: \n");
    while (rep < NUM_HILOS)
    {
        for (int i = 0; i < 10; i++)
            printf("Datos[%i] = %.4f\n", (i + 1) + (N / NUM_HILOS * rep), datos[i + (N / NUM_HILOS * rep)]);
        rep++;
    }
    tiempoInicio = GetTickCount();
    for (int i = 0; i < NUM_HILOS; i++) {
        tareas[i].inicio = i * N / NUM_HILOS;
        tareas[i].fin = (i == NUM_HILOS - 1) ? N - 1 : (tareas[i].inicio + N / NUM_HILOS - 1);
        tareas[i].operacion = i;
        hilos[i] = CreateThread(NULL, 0, procesar, &tareas[i], 0, NULL);
    }
    WaitForMultipleObjects(NUM_HILOS, hilos, TRUE, INFINITE);
    tiempoFin = GetTickCount();
    tiempoTotal = tiempoFin - tiempoInicio;
    for (int i = 0; i < NUM_HILOS; i++)
        CloseHandle(hilos[i]);
    rep = 0;
    printf("\nDatos Procesados: \n");
    while (rep < NUM_HILOS)
    {
        for (int i = 0; i < 10; i++)
            printf("Datos[%i] = %.4f\n", (i + 1) + (N / NUM_HILOS * rep), datos[i + (N / NUM_HILOS * rep)]);
        rep++;
    }
    printf("\nTiempo total de ejecucion: %lu ms\n", tiempoTotal);
    printf("Numero de datos: %i\n", N);
    printf("Numero de nucleos: %i", NUM_HILOS);
    return 0;
}

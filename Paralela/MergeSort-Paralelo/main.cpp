#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

// Umbral mínimo para crear tareas paralelas
#define minTareas 1000

void merge(vector<int>& arr, int inicio, int mid, int fin) {
    int n1 = mid - inicio + 1;
    int n2 = fin - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortParalelo(vector<int>& arr, int inicio, int fin) {
    if (inicio >= fin) return;

    int mid = (inicio + fin) / 2;
    int size = fin - inicio + 1;

    // Solo crear tareas si el tamaño del vector es grande, si es pequeño no sería optimo usar paralelismo
    if (size > minTareas) {
        #pragma omp task shared(arr)
                mergeSortParalelo(arr, inicio, mid);

        #pragma omp task shared(arr)
                mergeSortParalelo(arr, mid + 1, fin);

        #pragma omp taskwait
    }
    else {
        // Caso secuencial para segmentos pequeños
        mergeSortParalelo(arr, inicio, mid);
        mergeSortParalelo(arr, mid + 1, fin);
    }

    merge(arr, inicio, mid, fin);
}

int main() {
    srand(time(0));
    int cantidad;

    cout << "Ingrese el numero de datos para el vector: ";
    cin >> cantidad;

    vector<int> datos(cantidad);
    for (int i = 0; i < cantidad; i++) {
        datos[i] = rand() % 10000;
    }

    cout << "Ordenando con Merge Sort Paralelo" << endl;

    double inicio_tiempo = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        {
            mergeSortParalelo(datos, 0, datos.size() - 1);
        }
    }

    double fin_tiempo = omp_get_wtime();
    cout << "Tiempo de ejecucion: " << (fin_tiempo - inicio_tiempo) << " segundos\n";

    return 0;
}

#include <iostream>
#include <omp.h>
#define N 10

using namespace std;

int main()
{
    /*
    //Probamos las variables compartidas y privadas
    int total=10;
    #pragma omp parallel private(total)
    {
        total=omp_get_thread_num();
        printf("Hilo %d, total = %d\n", omp_get_thread_num(),total);
    }
    printf("Al final total quedo con: %d", total);
    return 0;
    */


    //Probamos la directiva del for
    int arr[N], suma=0;
    for(int i=0; i<N; i++) arr[i]=i;

    double inicio = omp_get_wtime();
    #pragma omp parallel for reduction (+:suma)
    for(int i=0; i < N; i++){
        cout<<"Soy el hilo "<<omp_get_thread_num()<<"en la iteracion "<<i<<endl;
        suma+=arr[i];
    }
    double fin = omp_get_wtime();

    printf("Tiempo paralelo: %f\n", fin-inicio);
    printf("Suma paralelo: %d\n", suma);

    int sumaSeq=0;
    inicio = omp_get_wtime();
    for(int i =0; i<N; i++){
        sumaSeq+=i;
    }
    fin = omp_get_wtime();
    printf("Tiempo secuencial: %f\n", fin-inicio);
    printf("Suma secuencial: %d\n", sumaSeq);

    /*
    // probamos la region critica
    int contador=0;
    #pragma omp parallel
    {
        #pragma omp critical
        {
            contador++;
            printf("Hilo %d, contador actual= %d\n", omp_get_thread_num(), contador);
        }

    }
    printf("Contador final: %d\n", contador);
    */

    /*#pragma omp parallel
    {
        #pragma omp single
        {
            for(int i = 0; i < 12; i++) {
                #pragma omp task
                printf("Tarea %d ejecutara por el hilo %d\n", i, omp_get_thread_num());
            }
        }
    }*/
}

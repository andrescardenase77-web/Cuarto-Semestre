#include <iostream>
#include <stdio.h>
# include <omp.h>

#define N 300

using namespace std;

int main()
{
    int matrizA [N][N];
    int matrizB [N][N];
    int matrizSuma [N][N];
    int matrizResta [N][N];


    for(int i = 0; i < N; i++){
        for(int j =0; j< N; j++){
            matrizA[i][j] = j*10;
            matrizB[i][j] = j*2;
            matrizSuma[i][j] = 0;
            matrizResta[i][j] = 0;

        }
    }

    double t0 = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic)
    for(int i = 0; i < N; i++){
        for(int j =0; j< N; j++){
            matrizSuma[i][j] = matrizA[i][j] + matrizB[i][j];
            matrizResta[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
    double t1 = omp_get_wtime();

    printf("El tiempo fue de %f con el tamanio de las matrices cuadradas %d x %d", t1-t0, N, N);


    return 0;
}

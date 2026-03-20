#include <iostream>
#include <omp.h>

using namespace std;

int main()
{

    //omp_set_num_threads(2);
    //Define una region en paralelo
    omp_get_wtime();
    #pragma omp parallel num_threads(4)
    {
        int id=omp_get_thread_num();
        int total=omp_get_num_threads();
        printf("Hola desde el hilo %d de %d\n", id, total);
    }




    return 0;
}

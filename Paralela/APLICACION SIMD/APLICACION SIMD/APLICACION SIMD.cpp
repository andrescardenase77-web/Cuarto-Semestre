#include <iostream>
#include <xmmintrin.h>
#include <stdio.h>

#define N 1000000

void iniciarVectores(int A[], int B[]) {

}

int main()
{
    float a[4] = { 1,2,3,4 };
    float b[4] = { 5,6,7,8 };
    float result[4];

    __m128 va = _mm_loadu_ps(a);
    __m128 vb = _mm_loadu_ps(b);
    __m128 vresult = _mm_add_ps(va, vb);
    _mm_storeu_ps(result, vresult);

    for (int i = 0;i < 4;i++) {
        printf("result[%d] = %.1f\n", i, result[i]);
    }
    if (1000000 % 4)
        printf("si");
    else
        printf("no");
    return 0;
}

#include <emmintrin.h> //v3
#include <smmintrin.h> //v4


#include <stdio.h>

int main(){
    __m128 row1_A = _mm_set_ps (1, 1, 1, 1);
    __m128 row2_A = _mm_set_ps (1, 1, 1, 1);
    __m128 row3_A = _mm_set_ps (1, 1, 1, 1);
    __m128 row4_A = _mm_set_ps (1, 1, 1, 1);

    __m128 colum1_B = _mm_set_ps (1, 1, 1, 1);
    __m128 colum2_B = _mm_set_ps (1, 1, 1, 1);
    __m128 colum3_B = _mm_set_ps (1, 1, 1, 1);
    __m128 colum4_B = _mm_set_ps (1, 1, 1, 1);

    //First resulting colum
    __m128 c1_temp = _mm_mul_ps (row1_A, colum1_B);
    __m128 c1_temp2 = _mm_mul_ps (row2_A, colum1_B);
    __m128 c1_temp3 = _mm_mul_ps (row3_A, colum1_B);
    __m128 c1_temp4 = _mm_mul_ps (row4_A, colum1_B);

    //Second resulting colum
    __m128 c2_temp = _mm_mul_ps (row1_A, colum2_B);
    __m128 c2_temp2 = _mm_mul_ps (row2_A, colum2_B);
    __m128 c2_temp3 = _mm_mul_ps (row3_A, colum2_B);
    __m128 c2_temp4 = _mm_mul_ps (row4_A, colum2_B);

    //Third resulting colum
    __m128 c3_temp = _mm_mul_ps (row1_A,  colum3_B);
    __m128 c3_temp2 = _mm_mul_ps (row2_A, colum3_B);
    __m128 c3_temp3 = _mm_mul_ps (row3_A, colum3_B);
    __m128 c3_temp4 = _mm_mul_ps (row4_A, colum3_B);

    //Fourth resulting colum
    __m128 c4_temp = _mm_mul_ps (row1_A,  colum4_B);
    __m128 c4_temp2 = _mm_mul_ps (row2_A, colum4_B);
    __m128 c4_temp3 = _mm_mul_ps (row3_A, colum4_B);
    __m128 c4_temp4 = _mm_mul_ps (row4_A, colum4_B);
    

    //Print first row
    printf("%f, ",__mm_extract_ps(c1_temp,0));
    printf("%f, ", __mm_extract_ps(c2_temp,0));
    printf("%f, ", __mm_extract_ps(c3_temp,0));
    printf("%f \n",__mm_extract_ps(c2_temp,0));

    //Print second row
    printf("%f, ", __mm_extract_ps(c1_temp2,0));
    printf("%f, ", __mm_extract_ps(c2_temp2,0));
    printf("%f, ", __mm_extract_ps(c3_temp2,0));
    printf("%f \n",__mm_extract_ps(c2_temp2,0));

    //Print third row
    printf("%f, ",  __mm_extract_ps(c1_temp3,0));
    printf("%f, ",  __mm_extract_ps(c2_temp3,0));
    printf("%f, ",  __mm_extract_ps(c3_temp3,0));
    printf("%f \n", __mm_extract_ps(c2_temp3,0));

    //Print fourth row
    printf("%f, ",  __mm_extract_ps(c1_temp4,0));
    printf("%f, ",  __mm_extract_ps(c2_temp4,0));
    printf("%f, ",  __mm_extract_ps(c3_temp4,0));
    printf("%f \n", __mm_extract_ps(c2_temp4,0));

}
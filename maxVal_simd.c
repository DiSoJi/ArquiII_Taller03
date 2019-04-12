
#include <emmintrin.h> //v3
#include <smmintrin.h> //v4


#include <stdio.h>

int main(){
    int temp_i = 0; //bigger to smaller ordered to help memory aligning in case optimizations are off
    short temp_value = 0;
    short temp_a;
    short temp_b;
    short temp_c = 0;
    short a[8] = {0,0,0,0,0,0,0,0};
    short b[8] = {0,0,0,0,0,0,0,0};
    for (int i=0; i<16; i++){
        if (i < 8){
            temp_i = i + 1;
            printf("Please insert the value %d of the first row \n",temp_i);
            scanf("%hu",&temp_value);
            a[i] = temp_value;

        }else{
            temp_i = i - 7;
            printf("Please insert the value %d of the second row \n",temp_i);
            temp_i-=1;
            scanf("%hu",&temp_value);
            b[temp_i] = temp_value;
        }
    }
    //store vectors in memory. two vectors of 8 short values gives a 2x8 matrix.
    __m128i vector1 = _mm_set_epi16(a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);
    __m128i vector2 = _mm_set_epi16(b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]);
    
    __m128i c = _mm_cmpgt_epi16 (vector1, vector2);
    printf("Vector Resultante = (");
    
    temp_c = _mm_extract_epi16(c,7);
    //temp_c := (_mm_extract_epi16(c,7) == 0) ? _mm_extract_epi16(a,7): _mm_extract_epi16(b,7)
    if (!temp_c) temp_c = _mm_extract_epi16(vector2,7);
    else temp_c = _mm_extract_epi16(vector1,7);
    printf("%hu",temp_c);
    printf(", ");
    temp_c = _mm_extract_epi16(c,6);
    if (!temp_c) temp_c = _mm_extract_epi16(vector2,6);
    else temp_c = _mm_extract_epi16(vector1,6);
    printf("%hu",temp_c);
    printf(", ");
    temp_c = _mm_extract_epi16(c,5);
    if (!temp_c) temp_c = _mm_extract_epi16(vector2,5);
    else temp_c = _mm_extract_epi16(vector1,5);
    printf("%hu",temp_c);
    printf(", ");
    temp_c = _mm_extract_epi16(c,4);
    if (!temp_c) temp_c = _mm_extract_epi16(vector2,4);
    else temp_c = _mm_extract_epi16(vector1,4);
    printf("%hu",temp_c);
    printf(", ");
    temp_c = _mm_extract_epi16(c,3);
    if (!temp_c) temp_c = _mm_extract_epi16(vector2,3);
    else temp_c = _mm_extract_epi16(vector1,3);
    printf("%hu",temp_c);
    printf(", ");
    temp_c = _mm_extract_epi16(c,2);
    if (!temp_c) temp_c = _mm_extract_epi16(vector2,2);
    else temp_c = _mm_extract_epi16(vector1,2);
    printf("%hu",temp_c);
    printf(", ");
    temp_c = _mm_extract_epi16(c,1);
    if (!temp_c) temp_c = _mm_extract_epi16(vector2,1);
    else temp_c = _mm_extract_epi16(vector1,1);
    printf("%hu",temp_c);
    printf(", ");
    temp_c = _mm_extract_epi16(c,0);
    if (!temp_c) temp_c = _mm_extract_epi16(vector2,0);
    else temp_c = _mm_extract_epi16(vector1,0);
    printf("%hu",temp_c);
    printf(")");
    
    
    /*for (int i = 7;i <= 0; i--){
        printf(", %hu ",c[i]);
    }
    printf(" )");*/
    
    


    printf("\nProgram ended succefully\n");



     
    return 0;
}

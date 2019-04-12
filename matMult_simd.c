
#include <emmintrin.h> //v3
#include <smmintrin.h> //v4


#include <stdio.h>

int main()
{

    // Three matrices to handle the original values and outputs not in __m128 data type
    float a[4][4] = { {1.2, 1.2, 1.2, 1.2}, {2.0, 2.0, 2.0, 2.0}, {3.0, 3.0, 3.0, 3.0}, {4.0, 4.0, 4.0, 4.0} };
    float b[4][4] = { {5.2, 5.2, 5.2, 5.2}, {6.0, 6.0, 6.0, 6.0}, {7.0, 7.0, 7.0, 7.0}, {8.0, 8.0, 8.0, 8.0} };
    float c[4][4] = { {0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0} };

    // Declaration of vectors to hanlde __m128i data type values
    __m128 vector1;
    __m128 vector2;
    __m128 vector3;

    // Multiplication using two for loops. Common rowxcolum algorithm
    for (int i = 0; i < 4; i++){
        vector1 = _mm_set_ps(a[i][0], a[i][1], a[i][2], a[i][3]); //Sets vector1 to be each of the rows of the first matrix
        for (int j = 0; j < 4; j++){
            vector2 = _mm_set_ps(b[0][j], b[1][j], b[2][j], b[3][j]);//Sets vector2 to be each of the colums of second matrix
            vector3 = _mm_mul_ps(vector1, vector2); //Multiplies each value in vector1 with the corresponding position in vector2, then saves according to position in vector3
            //Curiously enough __mm_extract_ps doesn't extracts a float but an int instead. This due to some register stuff according to research.
            //For that reason _mm_cvtss_f32 was used (this doesn't generate asm code but tells the data is float and should be handle like such)
            //So __mm_shuffle_ps is uded to move the data to the lower 32 bits of the register so it can be interpreted later as the single precision float we want.
            //And __MM_SHUFFLE is used to generate the operand for the desired value.
            c[i][j] = _mm_cvtss_f32( _mm_shuffle_ps(vector3, vector3, _MM_SHUFFLE(0, 0, 0, 0))) 
            +       _mm_cvtss_f32( _mm_shuffle_ps(vector3, vector3, _MM_SHUFFLE(0, 0, 0, 1))) 
            +       _mm_cvtss_f32( _mm_shuffle_ps(vector3, vector3, _MM_SHUFFLE(0, 0, 0, 2))) 
            +       _mm_cvtss_f32( _mm_shuffle_ps(vector3, vector3, _MM_SHUFFLE(0, 0, 0, 3))) 
            ;
        }
    }

    //Print the matrix in a stylish way
    printf("The resulting matrix is:  \n");
    for (int i = 0; i <4 ; i++) {
        printf("    %f", c[i][0]); 
        for (int j = 1; j < 4; j++){
            printf(", %f", c[i][j]);
        }
        printf("\n");
        
    }

    return 0;
}
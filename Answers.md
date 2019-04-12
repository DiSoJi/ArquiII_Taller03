
# Respuesta a las Preguntas

* ¿Qué es el set SSE, cuál es su utilidad y qué aplicaciones tiene?
Streaming SIMD Extensions. Es una extensión al set de instrucciones de x86 SSE contiene 70 nuevas instrucciones, de las cuales la mayoría trabajan en un flotantes de precisión simple.
Se utiliza como un medio de implementación de instrucciones SIMD, las cuales operan una instrucción sobre un conjunto de datos.
Se utiliza para desarrollar programas (comúnmente en lenguaje C) que permite realizar la misma operación sobre un conjunto de datos extenso (comúnmente vectores) de ahí el termino SIMD: Single Instruction Multiple Data.

* ¿Cómo realiza la compilación de un código c (.c) que utilice el set SSEx de Intel?

Se agrega la bandera -msee[ver] al comando de compilación. Donde ver es la versión: 2,3,4.1 (no se pone nada si es versión 1)

* ¿Qué importancia tienen la definición de variables y el alineamiento de memoria al trabajar con un set SIMD vectorial, como SSE?

La definición indica el tipo de datos que se va a manejar, por lo que puede causar mal interpretaciones de los datos.
El alineamiento de memoria presenta un problema similar, pues un error de alineamiento puede llevar a la corrupción de datos o malinterpretación de estos.

# Problemas Prácticos

## Respuestas

1. El código está almacenando y sumando dos vectores de 4 elementos para luego realizar una impresión en pantalla de cada valor. El código utiliza SSE2. Se utilizan las instrucciones:

    ```c
    __m128i _mm_set_epi32 (int e3, int e2, int e1, int e0) //Esta instrucción almacena 4 enteros de 32 bits en dst.

    ```

    ```c

    __m128i _mm_add_epi32 (__m128i a, __m128i b) //Suma los valores que hay en los vectores a y b y almacena el resultado en dst.

    ```

    ```c

    int _mm_extract_epi32 (__m128i a, const int imm8) //Extrae un valor de un vector (la posición es dada por imm8) y almacena el resultado en dst (además devuelve el valor).

    ```

2. Devuelve:

```bash

Hola Mundo desde SSE
Result ***********************
6       8       10      12

```

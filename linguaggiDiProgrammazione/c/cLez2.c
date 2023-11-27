#include <stdio.h>
int main(){
    /*
    #include ”file.h”  -> cerca nella directory corrente
    #include <file.h>  -> cerca nella directory sorgente
    */

   //direttiva define
   #define PI 3.14L
   #define max(x, y) ((x) < (y) ? (y) : (x))
   /*Tutte le istanze della stringa PI o di stringhe max(a, b)
    vengono sostituite*/

    /*
    condizionali, si verifica ciò che sta 
    tra ifdef e endif se PI è definita
    (si può anche usare ifndef per fare il contrario)

    #ifdef PI
    ...
    #else
    ...
    #endif
    */

    /*
    prompt$ gcc -c foo.c
    prompt$ gcc -c use-foo.c
    
    prompt$ gcc use-foo.o foo.o
    prompt$ a.out
    */
}
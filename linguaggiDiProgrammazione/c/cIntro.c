#include <stdio.h>
int main(){
    
    printf("Hello World\n");    /*stampa la stringa e va a capo*/

    char* ps;                   /*puntatore ad una locazione di memoria che contiene un carattere*/
    float** m;                  /*puntatore ad una locMem che contiene una locMem che contiene un float*/
    float v[42];                /*array di 42 float*/
    //float v2[];                 /*array di float di dimensione non specificata*/
    //float m2[42][];           /*array di 42 arrays di dimensione non specificata*/
    int (*pf) (int*, float*);   /*puntatore ad una funzione che accetta un puntatore ad
                                un int e un puntatore ad un float e che ritorna un intero*/
    //ARRAY
    float v2[] = {1, 3, 5.0};

    //STRINGHE
    /*le stringhe sono array di caratteri che terminano con il carattere nullo \0*/
    char stringa[] = "Dylan Dog"; /*uguale a: char stringa[] = {'D', 'y', ...}*/

    //STRUTTURE
    /*congregazioni di tipi diversi*/
    struct polar_complex{float magnitude; float angle;} c ={42.0, 3.14};
    struct polar_complex d = {0,0};
    float e = d.magnitude; //assegno 0 a e

    //PUNTATORI
    /*dato un qualunque tipo T, T* è il tipo "puntatore a T" */
    int x = 43;
    int* p = &x;    /*p contiene l'indirizzo di x*/
    int* q = p;     /*assegno un puntatore ad un altro*/
    int y = *p;     /*de-referenziazione, assegno a y il valore della variabile all'indirizzo puntato da p*/

    int v[] = {1, 2, 3, 4};
    int* p1 = v;
}
#include <stdio.h>
#include <stdlib.h>

/* includo i metodi di fattoriale.c */
#include "fattoriale.c"

int fatt(int);
/* -------------------- MAIN --------------------*/
/* va bene anche: int main(){ */
int main(int argc, char* argv[]) {

    printf("Ciao Mondo!\n%d sommato a %d = %d\n", 40, 2, 24);

    int p = 30; int q = 4;
    printf("%d sommato a %d = %d\n", p, q, p+q);

    /* stampa data una funzione */
    printf("il fattoriale di %d è: %d\n", 6, fatt(6));

    /* stampo gli argomenti 
    argc: numero degli argomenti scritti
    argv: array che contiene gli argomenti*/
    int i = 0; int n = 0;
    for(i=0; i<argc; i++){
        printf("arg %d = '%s'\n", i, argv[i]);
    }

    if(argc <= 1){
        fprintf(stderr, "Too few arguments.\n");
        exit(0);
    }
    /* converto una stringa in un int, non so a cosa serva in questo momento */
    n = atoi(argv[1]);
}
/* ------------------ END MAIN ------------------*/

/* funzione fattoriale, vedi il file aux */
/* int fatt(int n){
    if(n<0){
        printf("fatt: error: n = %d is negative.\n", n);
        exit(16);
    }
    if(n==0){
        return 0;
    }
    else{
        return n + fatt(n-1);
    } 
} */
#include <stdio.h>
#include <stdlib.h>

int fatt(int n){
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
}
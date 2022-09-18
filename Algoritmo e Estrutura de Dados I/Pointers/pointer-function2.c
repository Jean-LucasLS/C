#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int op(int c){
    c = 6;
    return c;
}

int main(Void){
    int k, *pointer;
    pointer = &k;
    k = op(k);
    printf("k = %d\n*pointer = %d", k, *pointer);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

void op(int *pointer){
    *pointer = 6;
}

int main(Void){
    int k, *pointer;
    pointer = &k;
    op(pointer);
    printf("k = %d\n*pointer = %d", k, *pointer);
    return 0;
}
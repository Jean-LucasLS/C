#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(){
    int k;
    int *pointer;
    pointer = &k;
    *pointer = 8;
    k = 6;
    printf("k = %d\n*pointer = %d\npointer = %d\n", k, *pointer, pointer);
    *pointer = 8;
    printf("k = %d\n*pointer = %d\npointer = %d", k, *pointer, pointer);
    return 0;
}
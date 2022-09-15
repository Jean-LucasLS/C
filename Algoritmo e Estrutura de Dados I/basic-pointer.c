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
    printf("k = %d\n*pointer = %d", k, *pointer);
    return 0;
}
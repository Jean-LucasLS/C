#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include "function.h"

int main(Void){
    int k = 0, *pointer;
    pointer = &k;
    op(pointer);
    printf("k = %d\n*pointer = %d", k, *pointer);
    return 0;
}
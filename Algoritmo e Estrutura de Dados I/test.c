#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(){
    int i, k=1;
    i = k++; // Primeiro iguala-se "i" a "k", e posteriormente há incremento em "k".
    printf("i = %d\nk = %d", i, k);
    k = 1;
    i = ++k; // Primeiro há incremento em "k", depois este é igualado a "i".
    printf("\ni = %d\nk = %d", i, k);
    return 0;
}
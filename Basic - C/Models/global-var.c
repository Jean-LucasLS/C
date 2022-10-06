#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int gVariavel = 2;

int main(Void){
    f();
    f();
    gVariavel++;
    f();
    gVariavel++;
    gVariavel++;
    printf("%d", gVariavel);
    return 0;
}

void f(void){
    gVariavel++;
}
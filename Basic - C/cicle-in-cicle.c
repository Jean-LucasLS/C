#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(){
    int i, j;
    for (i = 1; i < 5; i++){
        printf("%d\n", i);
        for (j = 1; j < 3; j++){ // Para cada comando de "i" ocorrerá toda a sequência de "j".
            printf("%d\n", j);}
    }
    return 0;
}
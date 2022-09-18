#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(void){
    int i, j;
    int n[2][2] = {1, 2, 3, 4}; // n[1][1] = 1, n[2][1] = 2, n[1][2] = 3, n[2][2] = 4.
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            printf("%d\n", n[j][i]);
        }
    }
    return 0;
}
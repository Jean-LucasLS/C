#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(void){
    int i, j;
    int n[2][2] = {1, 2, 3, 4}; // n[0][0] = 1, n[1][0] = 2, n[0][1] = 3, n[1][1] = 4.
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            printf("%d\n", n[j][i]);
        }
    }
    return 0;
}
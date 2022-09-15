#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(Void){
    int n[5] = {1, 2, 3, 4, 5}, i; // Esta estrutura atribui valores ao vetor n[5] na ordem "{n[0], n[1], n[2], n[3], n[4]} -> {1, 2, 3, 4, 5}"".
    for (i = 0; i < 5; i++){
        printf("%d\n", n[i]);}
    return 0;
}
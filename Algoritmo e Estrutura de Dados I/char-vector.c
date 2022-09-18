#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(void){
    char nome[5];
    for (i = 0; i < 5; i++){
        scanf("%c", &nome[i]);
    }
    for (i = 0; i < 5; i++){
        printf("%c", nome[i]);
    }
    return 0;
}
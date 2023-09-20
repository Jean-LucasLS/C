#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(){
    float x, p;
    scanf("%f %f", &x, &p);
    do{                               // Primeiro realiza-se o comando e depois se faz o teste.
        p++;}
    while (p<x);    
    printf("%.2f", p); // O formato "%.2f" tem como ".2" a indicação que só printar-se-á duas casas decimais depois da vírgula (aplicável para variáveis FLOAT, DOUBLE etc).
    return 0; 
    }
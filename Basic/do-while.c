#include <stdio.h>
#include <stdlib.h>

int main(){
    float x, p;
    scanf("%f %f", &x, &p);
    do{                               //primeiro realiza o comando e depois faz o teste.
        p++;}
    while (p<x);    
    printf("%.2f", p);
    return 0; 
    }
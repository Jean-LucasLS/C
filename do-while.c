#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, p;
    scanf("%d %d", &x, &p);
    do{                      // Primeiro executa o comando e depois faz o teste
        p++;}
    while (p<x);    
    printf("%d", p);
    return 0; 
    }
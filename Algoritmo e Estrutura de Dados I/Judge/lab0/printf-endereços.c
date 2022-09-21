#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
// Para imprimir um endereço no "printf", utiliza-se "%x".
int main(Void){
    int a = 10;
    int *p;
    p = &a;
    printf("%x", &a); // Imprime o endereço de "a".
    printf("\n%x", p); // Imprime o endereço da variável ao qual o ponteiro *p está apontando.
    printf("\n%d", *p); // Imprime a variável à qual o pointeiro está apontando.
    printf("\n%x", &p); // Imprime o endereço do próprio ponteiro.
    return 0;
}
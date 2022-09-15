#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

/*Estrutura com ponto de interrogação que executa
a primera ação se a condição for verdadeira, e a
segunda caso não: "condição ? (ação1)  :  (ação2);"
*/

int main(){
    int n = 2, n2 = 3, x;
    n > n2 ? printf("n e maior\n") : printf("n e menor\n");
    n > n2 ? (n = n*n2) : (n2 *= 2);
    printf("%d %d", n, n2);
   return 0;
}
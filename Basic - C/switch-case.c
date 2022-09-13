#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

/* Estrutura aonde "(n)" é analisado, e para cada caso 
ter-se-á uma linha de código caso seja aquele o valor de "n".
Default é acionado quando "n" não aparecer em algum "case". */

int main(){
    int n;
    printf("Digite um numero de 1 a 7:\n");
    scanf("%d", &n);
    switch (n){ 
        case 1:
            printf("Domingo");
            break;
        case 2:
            printf("Segunda");
            break;
        case 3:
            printf("Terça");
            break;
        case 4:
            printf("Quarta");
            break;
        case 5:
            printf("Quinta");
            break;
        case 6:
            printf("Sexta");
            break;
        case 7:
            printf("Sabado");
        default:
            printf("Nao existente");
    }
    return 0;
}
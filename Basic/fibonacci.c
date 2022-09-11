#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(){
    int n1 = 0, n2 = 1, soma, n, i;
    printf("Digite o numero de valores que deseja da sequencia de Fibonacci:\n");
    scanf("%d", &n);
    printf("%d\n", n2);
    for (i=0; i < n; i++){
        soma = n1 + n2;
        n1 = n2;
        n2 = soma;
        printf("%d\n", soma);
    }
    return 0;
}
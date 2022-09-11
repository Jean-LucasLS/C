#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(){
    int n1 = 0, n2 = 1, soma, n, i;
    printf("Digite o numero de valores que deseja da sequencia de Fibonacci:\n");
    scanf("%d", &n);
    printf("%d\n", n2); // Caso "n" seja zero, mostrar-se-á o número um somente.
    for (i=0; i < n; i++){ // Laço que irá conduzir a sequência
        soma = n1 + n2; // a soma dos dois ditará o próximo "n2"
        n1 = n2; // o "n1" avançará para "n2", enquanto "n2" avança para "soma"
        n2 = soma;
        printf("%d\n", soma);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(){
    int n, aux;
    printf("Digite o numero que sera invertido:\n");
    scanf("%d", &n);
    if (n >= 0)
        do{
            aux = n % 10; // O auxiliar será o resto da divisão do "n" por 10, indicando qual número está na casa da unidade, dezena, centena etc.
            printf("%d", aux);
            n /= 10;} // Com o "n" sendo dividido por 10, até que ele assuma valor 0 (inteiro), ainda haverá números a serem printados.
        while (n != 0);
    else
        printf("-"); // Caso o número seja negativo, irá colocar-se "-", transformar o número em positivo, e realizar a mesma operação anterior.
        n /= -1;
        do{
            aux = n % 10;
            printf("%d", aux);
            n /= 10;} 
        while (n != 0);
    return 0;
}
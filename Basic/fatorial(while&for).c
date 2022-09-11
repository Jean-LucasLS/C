#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(){
    int n, Nfor, fat = 1, fatFor = 1, i; // Criou-se "n" e "fat" para calcular fatorial com WHILE, e "Nfor" e "fatFor" para calcular-se fatorial utilizando-se FOR
    printf("Digite o numero que pretende calcular o fatorial:\n");
    scanf("%d", &n);
    Nfor = n;
    while(n > 1){ // Laço while que continua as multiplicações até se obter o somatório fatorial
        fat = fat * n; // O "fat" foi designado 1 no começo para que esta operação fosse possível
        n--; // O "n" diminui cada vez que se multiplica "fat", acumulando as multiplicações
    }
    printf("O fatorial equivale a %d (while)\n", fat);
    for (i>1; i = Nfor; i++){
        fatFor = fatFor * Nfor;
        Nfor--;
    }
    printf("O fatorial equivale a %d (for)", fatFor);
    return 0;
}
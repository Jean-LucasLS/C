#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(){
    int idade;
    printf("Digite a sua idade:\n");
    scanf("%d", &idade); // O código recebe a idade para posteriormente, em uma estrutura if - else-if - else, verificar em qual categoria está.
    printf("Voce esta na categoria: ");
    if (idade < 3)
        printf("Bebe");
    else if (idade >= 3 && idade < 13) // Os "&&" significam que as duas condições devem valer juntas. Se fosse "||" significaria "ou".
        printf("Crianca");
    else if (idade >= 13 && idade <18)
        printf("Adolescente");
    else
        printf("Adulto");
    return 0;        
}
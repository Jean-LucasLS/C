#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

/*Colocar o texto entre 
aspas duplas e colocar o
{"%" + "tipo de variável"}*/

int main(){
    char Validation = 'V'; // Teste de variável "char"
    float idade, peso, altura;
    printf("Digite sua idade, peso e altura:\n");
    scanf("%f %f %f", &idade, &peso, &altura);
    printf("%c\nSua idade equivale a %.0f\nSeu peso equivale a %.2f\nSua altura equivale a %.2f", Validation, idade, peso, altura);  
    return 0;
}
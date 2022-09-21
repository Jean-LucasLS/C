#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(Void){
    char t[100];
    gets(t); // A função "gets()" é um tipo de "scanf" aplicado para vetor de caracteres.
    printf("%s", t); // Tudo o que for escrito em "t" (com limite de 100 char) será printado com "%s" (string).
    return 0;
}
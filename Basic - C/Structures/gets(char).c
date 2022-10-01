#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main(Void){
    int i;
    char t[100], f[100];
    gets(t); // A função "gets()" é um tipo de "scanf" aplicado para vetores de caracteres.
    for (i = 0; i < 100; i++){
        f[i] = t[i];
    }
    printf("%s\n", t); // Tudo o que for escrito em "t" (com limite de 100 char) será printado com "%s" (string).
    printf("%s", f);
    return 0;
}
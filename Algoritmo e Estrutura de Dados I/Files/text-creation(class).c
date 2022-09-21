#include <stdio.h>
#include <stdlib.h>

int main(Void){
    FILE *arquivo; // Declaração de uma FILE tipo ponteiro.
    char texto[100], nome[100];
    gets(texto);
    gets(nome);
    arquivo = fopen(nome, "w");
    fputs(texto, arquivo);
    fclose(arquivo);
    return 0;
}
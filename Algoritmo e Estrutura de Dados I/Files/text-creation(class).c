#include <stdio.h>
#include <stdlib.h>

int main(Void){
    FILE *arquivo; // Declaração de uma FILE tipo ponteiro.
    char texto[100], nome[100];
    printf("Digite o nome do arquivo:\n");
    gets(nome);
    printf("Digite o texto que deseja salvar:\n");
    gets(texto);
    arquivo = fopen(nome, "w");
    fputs(texto, arquivo);
    fclose(arquivo);
    return 0;
}
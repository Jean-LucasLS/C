#include <stdio.h>
#include <stdlib.h>

int main(Void){
    FILE *arquivo; // Declaração de uma FILE tipo ponteiro.
    char texto[5], nome[100];
    printf("Digite o nome do arquivo:\n");
    gets(nome); // Leitura do vetor Nome, que será o nome do arquivo texto o qual será lido.
    arquivo = fopen(nome, "r");
    fgets(texto, 5, arquivo); // O código só lerá a quantidade de caracteres X determinada pelo vetor texto["X"].
    printf("%s", texto);
    fclose(arquivo);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(Void){
    FILE *arquivo; // Declaração de uma FILE tipo ponteiro.
    char texto[100], nome[100];
    printf("Digite o nome do arquivo:\n");
    gets(nome); // Leitura do vetor Nome, que será o nome do arquivo texto o qual será lido.
    arquivo = fopen(nome, "r");
    while (!feof(arquivo)){ // "feof" é "end of file", então lê do começo até o fim.
        fgets(texto, 100, arquivo); // O código só lerá a quantidade de caracteres X determinada pelo vetor texto["X"]. A função "fgets" lê somente até o primeiro \n que encontrar, por isso a necessidade de um vetor.
        printf("%s", texto);
    }
    fclose(arquivo);
    return 0;
}
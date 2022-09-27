#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char descricao[50];
    int preco;
    int quantidade;
}produto;

int main(){
    FILE *arq;
    produto prod;
    arq = fopen("myfile1.bin", "rb");
    while (fread(&prod, sizeof(prod), 1, arq)){
    printf("%s\n", prod.descricao);
    printf("%d\n", prod.preco);
    printf("%d\n\n", prod.quantidade);
    }
    return 0;
}
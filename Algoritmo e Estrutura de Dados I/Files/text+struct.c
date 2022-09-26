#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
}data;

void main(){
    data abagail; // A variável "abagail" é do tipo "data", sendo "data" um registro declarado.
    FILE *arq;
    char title[100];
    printf("Digite o nome do arquivo:\n");
    gets(title);
    printf("Digite o seu nome:\n");
    gets(abagail.nome);
    printf("Digite sua idade:\n");
    scanf("%d", &abagail.idade);
    arq = fopen(title, "w");
    fprintf(arq, "Name: %s\nIdade: %d", abagail.nome, abagail.idade); // Este print será feito no arquivo texto criado.
    fclose(arq); 
}
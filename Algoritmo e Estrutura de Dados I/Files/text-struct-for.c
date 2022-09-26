#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
}data;

void main(){
    data *abagail;
    FILE *arq;
    int n, i;
    char title[100];
    printf("Digite o nome do arquivo:\n");
    gets(title);
    printf("Digite quantas pessoas quer inserir:\n");
    scanf("%d", &n);
    abagail = (data *)malloc(n*sizeof(data));
    arq = fopen(title, "w");
    for (i = 0; i < n; i++){ // Identação para inserir "n" estruturas do tipo "data".
        printf("Digite o seu nome:\n");
        scanf("%s", &abagail[i].nome); // O "%s" faz com que o scanf consiga ler diretamente um vetor de caracteres.
        //gets(abagail[i].nome); <-------> A função "gets" não funciona neste caso.
        printf("Digite sua idade:\n");
        scanf("%d", &abagail[i].idade);
        fprintf(arq, "Name: %s\nIdade: %d", abagail[i].nome, abagail[i].idade);
        if (i != n - 1){
            fprintf(arq, "\n");
        }
    }
    fclose(arq); 
}
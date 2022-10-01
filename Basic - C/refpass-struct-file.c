#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
}data;

void mugman(int n, data *abagail, FILE *c){
    int i;    
    char title[50];
    printf("Digite o nome do arquivo:\n");
    scanf("%s", &title);
    abagail = (data *)malloc(n*sizeof(data));
    c = fopen(title, "w");
    for (i = 0; i < n; i++){
        printf("Digite o nome:\n");
        scanf("%s", &abagail[i].nome);
        printf("Digite a idade:\n");
        scanf("%d", &abagail[i].idade);
        fprintf(c, "Name: %s\nIdade: %d", abagail[i].nome, abagail[i].idade);
        if (i != n - 1){
            fprintf(c, "\n");
        }
    }
    fclose(c);
}

void main(){
    int n;
    FILE *c;
    data *abagail;
    printf("Digite quantas pessoas quer inserir:\n");
    scanf("%d", &n);
    mugman(n, abagail, c);
}
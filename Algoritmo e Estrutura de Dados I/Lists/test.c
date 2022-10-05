#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct{
    int last;
    int size;
    int list[N];
}Jujuba;

void Start(Jujuba *listaux){
    int i=0;
    listaux->last=0; // A seta "->" significa acesso ao campo de uma estrutura passada por referência, similar a "listaux.last = 0" que é por parâmetro.
    listaux->size=0;
    for(i=0; i<N; i++){
        listaux->list[i]=0;
    }
}

Jujuba InsertOnEnd(Jujuba *listaux, int a){
    listaux->last++;
    listaux->list[listaux->last-1]=a;
    listaux->size++;
    return *listaux;
}

void ListPrint(Jujuba listaux){
    int i=0;
    printf("List printing:\n");
    for(i=0; i<(listaux.size); i++){
        printf("%d\n", listaux.list[i]);
    }
}

void main(void){
    Jujuba list;
    int a = 10, b = 3, i=0;
    Start(&list);
    InsertOnEnd(&list, a);
    InsertOnEnd(&list, b);
    ListPrint(list);
}
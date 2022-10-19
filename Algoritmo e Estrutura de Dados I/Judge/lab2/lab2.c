/* NOME: Jean-Lucas Luquetti Silva | RA: 120443 | AED I - Turma: IC */
#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct{
    int value;
    int next;
}Info;

typedef struct{ // Declaração da estrutura que será utilizada para a lista.
    int size;
    int first;
    int last;
    int free[N];
    Info element[N];
}Jujuba;

void Start(Jujuba *listaux){
    int i;
    listaux -> size = 0;
    listaux -> first = -1;
    listaux -> last = -1;
    for(i=0; i<N; i++){
        listaux -> element[i].value = 0;
        listaux -> element[i].next = -1;
        listaux -> free[i] = 1;
    }
}

int Insert(Jujuba *listaux, int RA, int pfree){
    int i, prev;
    listaux -> element[pfree].value = RA;
    listaux -> free[pfree] = 0;
    if(listaux -> size == 0){
        listaux -> first = pfree;
        listaux -> last = pfree;
        listaux -> size+=1;
        return 0;
    }
    else if(RA < listaux -> element[listaux -> first].value){
        listaux -> element[pfree].next = listaux -> first;
        listaux -> first = pfree;
        listaux -> size+=1;
        return 0;
    }
    else if(RA > listaux -> element[listaux -> last].value){
        listaux -> element[listaux -> last].next = pfree;
        listaux -> last = pfree;
        listaux -> size+=1;
        return 0;
    }
    else{
        for(i = listaux -> first; i != -1; i = listaux -> element[i].next){ // element[listaux->first].next
            if(RA < listaux -> element[i].value){                            
                listaux -> element[prev].next = pfree;
                listaux -> element[pfree].next = i;
                return 0;              
            }
        prev = i; // O "prev" (previous) guarda o índice do RA anterior em relação ao que está sendo comparado.
        listaux->size+=1; 
        }
    }
}

void Remove(Jujuba *listaux, int RA){
    int i, prev;
    if(RA == listaux -> element[listaux -> first].value){
        listaux -> free[listaux -> first] = 1;
        listaux -> first = listaux -> element[listaux -> first].next;                             
        listaux -> size--;
        return;
    }
    for(i = listaux -> first; i != -1; i = listaux -> element[i].next){
        if(RA == listaux -> element[i].value){
            listaux -> free[i] = 1;
            listaux -> element[prev].next = listaux -> element[i].next;
            return;
        }
    prev = i;
    }
    printf("nao existe\n");
}

int SearchFree(Jujuba *listaux){ // Função que retorna o índice do primeiro espaço livre. Se não houver, retorna "-1".
    int pfree;
    for(pfree=0; pfree<N; pfree++){
        if(listaux -> free[pfree] == 1 ){
            return pfree;
        }
    }
    return -1;
}

int main(){
    int L, op, RA, i, j=0, pfree;
    int c11, c12, c13, c14, c15, c16, c17, c18; // Contadores para os anos de 2011-2018.
    Jujuba list;
    Start(&list);
    scanf("%d", &L);
    for(i=0; i<L; i++){
        scanf("%d %d", &op, &RA); // O "op" é a indicação de qual operação será realizada.
        switch (op){
            case 1:
                pfree = SearchFree(&list); // "pfree" tem como intuito verificar o índice do espaço livre. Caso seja "-1", a lista está cheia.
                if (pfree != -1){          // Caso o valor retornado seja diferente de -1, significa que a lista não está cheia.
                Insert(&list, RA, pfree);

                for(j = list.first; j != -1; j = list.element[j].next){
                    printf("%d\n", list.element[j].value);
                }

                }
                else{ // Caso seja "-1", a lista está cheia.
                    printf("lista cheia.\n");
                }
                break;
            case 2:
                Remove(&list, RA);

                for(j = list.first; j != -1; j = list.element[j].next){
                     printf("%d\n", list.element[j].value);
                }
                break;
        }
    }
    printf("%d\n", list.first);
    for(j = list.first; j != -1; j = list.element[j].next){
        printf("%d ", list.element[j].value);
    }
    return 0;
}
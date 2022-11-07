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
            if(RA == listaux -> element[listaux -> last].value){
                listaux -> last = prev;
                listaux -> free[i] = 1;
                listaux -> element[prev].next = -1;
                listaux -> size--;
                return;
            }
            listaux -> free[i] = 1;
            listaux -> element[prev].next = listaux -> element[i].next;
            listaux -> size--;
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

void PrintList(Jujuba *listaux){
    int j;
    for(j = listaux -> first; j != -1; j = listaux -> element[j].next){
        printf("%d ", listaux -> element[j].value);
    }
}

int main(){
    int L, op, RA, i, pfree;
    int c11=0, c12=0, c13=0, c14=0, c15=0, c16=0, c17=0, c18=0; // Contadores para os anos de 2011-2018.
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
                    if(RA / 1000 == 66){
                        c11+=1;
                    }
                    if(RA / 1000 == 76){
                        c12++;
                    }
                    if(RA / 1000 == 86){
                        c13++;
                    }
                    if(RA / 1000 == 96){
                        c14++;
                    }
                    if(RA / 1000 == 106){
                        c15++;
                    }
                    if(RA / 1000 == 116){
                        c16++;
                    }
                    if(RA / 1000 == 126){
                        c17++;
                    }
                    if(RA / 1000 == 136 || RA == 140000){
                        c18++;
                    }
                    PrintList(&list);
                }
                else{ // Caso seja "-1", a lista está cheia.
                    printf("lista cheia\n");
                    PrintList(&list);
                }
                printf("\n");
                break;
            case 2:
                Remove(&list, RA);
                PrintList(&list);
                printf("\n");
                break;
        }
    }
    printf("2011: %d\n2012: %d\n2013: %d\n2014: %d\n2015: %d\n2016: %d\n2017: %d\n2018: %d", c11, c12, c13, c14, c15, c16, c17, c18);
    return 0;
}
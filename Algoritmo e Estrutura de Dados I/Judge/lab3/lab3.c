/* NOME: Jean-Lucas Luquetti Silva | RA: 120443 | AED I - Turma: IC */
#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct Jockey{
    int idprod;
    int amount;
    float price;
    float profit;
    struct Jockey *next;
}Info;

typedef struct{ // Declaração da estrutura que será utilizada para a lista.
    int size;
    Info *first;
    Info *last;
}Jujuba;

void insertProduct(Jujuba *listaux, int pid, int pamount, float pprice){
    Info *p, *new, *prev;
    new = (Info *)malloc(sizeof(Info));
    new -> idprod = pid;
    new -> amount = pamount;
    new -> price = pprice;
    new -> profit = 0;
    new -> next = NULL;
    if(listaux -> size == 0){
        listaux -> first = new;
        listaux -> last = new;
        listaux -> size++;
        return;
    }
    for(p = listaux -> first; p != NULL; p = p -> next){
        if (p -> idprod == pid){
            printf("ja existe\n");
            return;
        }
    }
    for(p = listaux -> first; p != NULL; p = p -> next){
        if(p -> price < new -> price){
            if(p == listaux -> first){
                new -> next = listaux -> first;
                listaux -> first = new;
                listaux -> size++;
                return;
            }
            new -> next = p;
            prev -> next = new;
            listaux -> size++;
            return;
        }
        prev = p;
    }
    listaux -> last -> next = new;
    listaux -> last = new;
    listaux -> size++;
    return;
}

void addAmount(Jujuba *listaux, int pid, int pamount){
    Info *p;
    for(p = listaux -> first; p != NULL; p = p -> next){
        if(p -> idprod == pid){
            p -> amount += pamount;
            return;
        }
    }
    printf("nao existe\n");
    return;   
}

void buyProduct(Jujuba *listaux, int pid){
    Info *p;
    for(p = listaux -> first; p != NULL; p = p -> next){
        if(p -> idprod == pid){
            if(p -> amount != 0){
                p -> amount--;
                p -> profit += p -> price;
                return;
            }
            else{
                printf("nao existe\n");
                return;
            }
        }
    }
    printf("nao existe\n");
    return;    
}

void removeProduct(Jujuba *listaux, int pid){
    Info *p, *prev;
    if(listaux -> size == 0){
        printf("nao existe\n");
        return;
    }
    for(p = listaux -> first; p != NULL; p = p -> next){
        if(p -> idprod == pid){
            if(p == listaux -> first){
                listaux -> first = p -> next;
                free(p);
                listaux -> size--;
                return;
            }
            if(p == listaux -> last){
                listaux -> last = prev;
                free(p);
                listaux -> size--;
                return;
            }
            prev -> next = p -> next;
            free(p);
            listaux -> size--;
            return;
        }
        prev = p;
    }
    printf("nao existe\n");
    return;
}

int main(){
    int L, pid, pamount, op, i;
    float pprice;
    Jujuba list;
    Info *j;
    list.size = 0;
    list.first = NULL;
    list.last = NULL;
    scanf("%d", &L);
    for(i=0; i<L; i++){
        scanf("%d ", &op);
        switch (op){
            case 1:
                scanf("%d %d %f", &pid, &pamount, &pprice);
                insertProduct(&list, pid, pamount, pprice);
                break;
            case 2:
                scanf("%d %d", &pid, &pamount);
                addAmount(&list, pid, pamount);
                break;
            case 3:
                scanf("%d", &pid);
                buyProduct(&list, pid);
                break;
            case 4:
                scanf("%d", &pid);
                removeProduct(&list, pid);
                break;
        }
    }
    for(j = list.first; j != NULL; j = j -> next){
        printf("%d %f\n", j -> idprod, j -> profit);
        
    }
    return 0;
}
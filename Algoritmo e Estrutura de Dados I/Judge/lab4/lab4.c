#include <stdio.h>
#include <stdlib.h>

typedef struct Jockey{
    int value;
    struct Jockey *next;
    struct Jockey *prev;
}Info;

typedef struct{
    Info *first;
    Info *last;
    int size;
}Jujuba;

void startList(Jujuba *listaux, int number){
    Info *p, *i;
    p = (Info *)malloc(sizeof(Info));
    p -> value = number;
    if (listaux -> first == NULL){
        listaux -> first = p;
        listaux -> last = p;
        listaux -> size++;
    }
    else{
        listaux -> last -> next = p;
        p -> prev = listaux -> last;
        p -> next = listaux -> first;
        listaux -> last = p;
        listaux -> first -> prev = p;
        listaux -> size++;
    }
}

void insertValue(Jujuba *listaux, int newval, int newpos){
    Info *p, *j, *previous;
    int count = 0;
    p = (Info *)malloc(sizeof(Info));
    p -> value = newval;
    if (newpos == 0){
        listaux -> first -> prev = p;
        listaux -> last -> next = p;
        p -> next = listaux -> first;
        p -> prev = listaux -> last;
        listaux -> first = p;
        listaux -> size++;
        return;
    }
    else if (newpos == listaux -> size){
        listaux -> first -> prev = p;
        listaux -> last -> next = p;
        p -> next = listaux -> first;
        p -> prev = listaux -> last;
        listaux -> last = p;
        listaux -> size++;
        return;
    }
    else{
        for(j = listaux -> first; j != listaux -> last; j = j -> next){
            if (count == listaux -> size - 2){
                p -> prev = listaux -> last -> prev;
                p -> next = listaux -> last;
                listaux -> last -> prev = p;
                j -> next = p;
                listaux -> size++;
                return;
            }
            if (count == newpos){
                p -> prev = previous;
                p -> next = j;
                j -> prev = p;
                previous -> next = p;
                listaux -> size++;
                return;
            }
        previous = j;
        count++;
        }
    }
}

int tripleTest(Jujuba *listaux){
    Info *i, *j;
    int count = 0, seq[listaux -> size + 3], test, k = 0, midpos = -1;
    if (listaux -> size == 3){
        i = listaux -> first -> next;
        test = i -> value + listaux -> first -> value + listaux -> last -> value;
        if (test == 10){
            listaux -> first = NULL;
            listaux -> size = 0;
        }
        return -1;
    }
    if (listaux -> size > 3){
        for(j = listaux -> first; j != listaux -> last; j = j -> next){
            seq[count] = j -> value;
            count++;
        }
        seq[count] = listaux -> last -> value;
        count++;
        seq[count] = listaux -> first -> value;
        j = listaux -> first -> next;
        count++;
        seq[count] = j -> value;
        for(k = 0; k < listaux -> size; k++){
            test = seq[k] + seq[k+1] + seq[k+2];
            if (test == 10){
                midpos = k + 1;
                return midpos;
            }
        }
    }
    return -1;
}

void removeTriple(Jujuba *listaux, int midpos){
    Info *j, *i, *k, *m, *n;
    int count = 0;
    if (listaux -> size == 3){
        listaux -> first = NULL;
        listaux -> size = 0;
    }
    if (midpos == 1){
        j = listaux -> first -> next;
        i = j -> next;
        k = i -> next;
        listaux -> last -> next = k;
        listaux -> first = k;
        listaux -> size -= 3;
        return;
    }
    if (midpos < listaux -> size -2){
        for(j = listaux -> first; j != listaux -> last; j = j -> next){
            k = j -> next;
            m = k -> next;
            i = j -> prev;
            n = i -> prev;
            if (count == midpos){
                n -> next = m;
                m -> prev = n;
                listaux -> size -= 3;
                return;
            }
            count++;
        }
    }
    if (midpos == listaux -> size - 2){
        for(j = listaux -> first; j != listaux -> last; j = j -> next){
            k = j -> next;
            m = k -> next;
            i = j -> prev;
            n = i -> prev;
            if (count == midpos){
                n -> next = m;
                m -> prev = n;
                listaux -> last = n;
                listaux -> size -= 3;
                return;
            }
            count++;
        }
    }
    if (midpos == listaux -> size - 1){
        i = listaux -> last -> prev;
        n = i -> prev;
        m = listaux -> first -> next;
        n -> next = m;
        m -> prev = n;
        listaux -> first = m;
        listaux -> last = n;
        listaux -> size -= 3;
        return;
    }
    if (midpos == listaux -> size){
        k = listaux -> first -> next;
        m = k -> next;
        i = listaux -> last -> prev;
        i -> next = m;
        m -> prev = i;
        listaux -> first = m;
        listaux -> last = i;
        listaux -> size -= 3;
        return;
    }
}

void printList(Jujuba *listaux){
    Info *j;
    for(j = listaux -> first; j != listaux -> last; j = j -> next){
        printf("%d ", j -> value);
    }
    printf("%d\n", listaux -> last -> value);  
}

int main(){
    int number, newval, newpos, i, midpos;
    Info *j;
    Jujuba list;
    list.first = NULL;
    list.size = 0;
    for(i = 0; i < 10; i++){
        scanf("%d", &number);
        startList(&list, number);
    }
    printList(&list);
    for(i = 0; i < 5; i++){
        scanf("%d %d", &newval, &newpos);
        insertValue(&list, newval, newpos);
        midpos = tripleTest(&list);
        if (midpos != -1){
            while (midpos != -1){
                removeTriple(&list, midpos);
                midpos = tripleTest(&list);
            }
        }
        if (list.size != 0){
            printList(&list);
    }   }
    if (list.size == 0){
        printf("ganhou");
    }
    else{
        printf("perdeu");
    }
    return 0;
}
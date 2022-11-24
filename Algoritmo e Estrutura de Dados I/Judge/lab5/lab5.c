#include <stdlib.h>
#include <stdio.h>
#define MAX 100

typedef struct{
    int first;
    int last;
    int size;
    int element[MAX];
}Jujuba;

void startRow(Jujuba *rowaux){
    int k;
    rowaux -> first = -1;
    rowaux -> last = -1;
    rowaux -> size = 0;
    for(k = 0; k < MAX; k++){
        rowaux -> element[k] = 0;
    }
}

void printRow(Jujuba *rowaux){
    int m;
    for(m = 0; m < MAX; m++){
        if (rowaux -> element[m] != 0){
            printf("%d ", rowaux -> element[m]);
        }
    }
}

void insertNumber(Jujuba *rowaux, int add){
    int j;
    if (rowaux -> size == 0){
        rowaux -> last = add;
        rowaux -> first = add;
        rowaux -> size++;
        rowaux -> element[0] = add;
        return;
    }
    if (rowaux -> size == 10){
        printf("overflow: lista cheia\n");
        return;
    }
    for(j = MAX -1 ; j > 0; j--){
        rowaux -> element[j] = rowaux -> element [j-1];
    }
    rowaux -> element[0] = add;
    rowaux -> first = add;
    rowaux -> size++;
    return;
}

void removeNumber(Jujuba *rowaux){
    int j;
    if (rowaux -> size == 0){
        printf("vazia\n");
        return;
    }
    if (rowaux -> size == 1){
        rowaux -> element[0] = 0;
        rowaux -> last = 0;
        rowaux -> first = 0;
        rowaux -> size--;
        return;
    }
    for(j = MAX - 1; j > 0; j--){
        if(rowaux -> element[j] != 0){
            rowaux -> element[j] = 0;
            rowaux -> size--;
            rowaux -> last = rowaux -> element[j-1];
            return;
        }
    }
}

void conclusion(Jujuba *rowaux){
    int j, temp, jtemp;
    if (rowaux -> size == 0){
        printf("vazia\n");
        return;
    }
    for(j = MAX - 1; j > 0; j--){
        if(rowaux -> element[j] != 0){
            jtemp = j;
            temp = rowaux -> element[j];
            for(j = MAX -1 ; j > 0; j--){
                rowaux -> element[j] = rowaux -> element [j-1];
            }
            rowaux -> element[jtemp+1] = 0;
            rowaux -> element[0] = temp;
            return;
        }
    }
}

int main(){
    Jujuba row;
    int i, numop, op, add;
    startRow(&row);
    scanf("%d", &numop);
    for(i = 0; i < numop; i++){
        scanf("%d", &op);
        switch (op){
            case 1:
                scanf(" %d", &add);
                insertNumber(&row, add);
                break;
            case 2:
                removeNumber(&row);
                break;
            case 3:
                conclusion(&row);
                break;
        }
    }
    printRow(&row);
    return 0;
}
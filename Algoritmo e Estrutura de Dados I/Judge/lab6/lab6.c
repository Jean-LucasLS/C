#include <stdio.h>
#include <stdlib.h>

typedef struct Jockey{
    int value;
    struct Jockey *ant;
}Info;

typedef struct{
    int size;
    Info *top;
}Jujuba;

void decToBin(Jujuba *stackaux, int n){
    int i, rest;
    while(n > 0){
        rest = n % 2;
        n = n / 2;
        stackNumber(stackaux, rest);
    }
}

void stackNumber(Jujuba *stackaux, int rest){
    Info *p;
    p = (Jujuba *)malloc(sizeof(Info));
    if(stackaux -> size == 0){
            stackaux -> top = p;
            p -> ant = NULL;
            p -> value = rest;
            stackaux -> size++;
    }
    else{
        p -> ant = stackaux -> top;
        stackaux -> top = p;
        p -> value = rest;
        stackaux -> size++;    
    }
}

void printBin(Jujuba *stackaux){
    Info *p;
    for(p = stackaux -> top; p != NULL; p = p -> ant){
        printf("%d", p -> value);
    }
    printf(" ");
}
void binToTransBin(Jujuba *stackaux){
    Info *p;
    for(p = stackaux -> top; p != NULL; p = p -> ant){
        if(p -> value == 1){
            p -> value = 0;
            printf("%d", p -> value);
        }
        else{
            p -> value = 1;
            printf("%d", p -> value);
        }
    }
    printf(" ");
}

int powMath(int count){
    int i, pot;
    pot = 1;
    for(i = 0; i < count; i++){
        pot *= 2;
    }
    return pot;
}

void transBinToTransDec(Jujuba *stackaux){
    int sum = 0, count;
    Info *p;
    count = stackaux -> size - 1;
    for(p = stackaux -> top; p != NULL; p = p -> ant){
        sum += p -> value * powMath(count);
        count--;        
    }
    printf("%d\n", sum);
}

void freeStack(Jujuba *stackaux){
    Info *p;
    for(p = stackaux -> top -> ant; p != NULL; p = p -> ant){
        free(stackaux -> top);
        stackaux -> top = p;
    }
    free(stackaux -> top);
    stackaux -> size = 0;
}

int main(){
    int L, i, n;
    Jujuba stack;
    stack.size = 0;
    scanf("%d", &L);
    for(i = 0; i < L; i++){
        scanf("%d", &n);
        printf("%d ", n);
        decToBin(&stack, n);
        printBin(&stack);
        binToTransBin(&stack);
        transBinToTransDec(&stack);
        freeStack(&stack);
    }
    return 0;
}
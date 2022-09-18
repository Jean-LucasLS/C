#include <stdio.h>
#include <stdlib.h>

int main(Void){
    int *k, c = 6;
    k = &c;
    salsichao(k);
    printf("\n%d", *k);
    return 0;
}

void salsichao( int *k){
    printf("Salsichao!\n");
    printf("%d", *k);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
    int z;
}data;

void main(){
    data abagail;
    abagail.x = 10;
    abagail.y = abagail.x;
    printf("Endereco de x: %x\ny = %d\nz = %d", &abagail.x, abagail.y, abagail.z);
}